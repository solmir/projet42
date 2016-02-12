/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 22:36:15 by alelievr          #+#    #+#             */
/*   Updated: 2016/02/02 00:45:03 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisatron.h"
#include "graphic_rfc.h"
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <pthread.h>

static void        set_timeout(int cs)
{
	struct timeval  timeout;

	ft_bzero(&timeout, sizeof(struct timeval));
	timeout.tv_sec = 42;
	if (setsockopt(cs, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
				sizeof(timeout)) < 0)
		ft_exit("Can't set timeout on client !\n");
}

int			client_connection(char *addr, int port)
{
	int                 sock;
	struct protoent     *proto;
	struct sockaddr_in  sin;

	if (port == 0)
		return (-1);
	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	if (!ft_strcmp(addr, "localhost"))
		sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	else
		sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		return (-1);
	set_timeout(sock);
	return (sock);
}

static void		perform_command(char *com, t_env *e)
{
	int		index;
	int		player;

	if (CHK_INFO(MEMORY_CASE, com))
	{
		index = ft_atoi(com + 3);
		player = ft_atoi(com + 3 + ft_intsize(index) + 1);
		if (e->map && index >= 0 && index < e->memory_size)
			e->map[index] = player;
	}
	if (CHK_INFO(RESET, com))
	{
		index = -1;
		if (e->map)
			while (++index < e->memory_size)
				e->map[index] = 0;
	}
	if (CHK_INFO(MEMORY_SIZE, com))
	{
		printf("message: %s\n", com);
		e->memory_size = atoi(com + 3);
		if (e->map)
			free(e->map);
		if (!(e->map = (char *)malloc(sizeof(char) * e->memory_size)))
			ft_exit("malloc failed !\n");
		ft_bzero(e->map, e->memory_size);
		e->grid_width = ft_sqrt(e->memory_size);
	}
	if (CHK_INFO(PLAYER_NUM, com))
	{
		e->player_number = atoi(com + 3);
	}
}

static void		interpret_code(char *d, t_env *e)
{
	if (CHK_CODE(d) == ERROR_CODE)
		ft_exit("an error occured : %s\n", d);
	if (CHK_CODE(d) == INFO_CODE)
		perform_command(d, e);
}

static void		parse_commands(char *d, t_env *e)
{
	static char		buff[0xF00];
	char			*save;

	if (buff[0])
	{
		ft_strncat(buff, d, sizeof(buff) - 1);
		interpret_code(buff, e);
		while (*d && *d != '\4')
			d++;
	}
	while (*d)
	{
		interpret_code(d, e);
		save = d;
		while (*d && *d != '\4')
			d++;
		if (!*d)
		{
			ft_strncpy(buff, save, sizeof(buff) - 1);
			printf("command not finished: %s\n", buff);
		}
		else
		{
			buff[0] = 0;
			d++;
		}
	}
}

static void		*wait_command(void *data);
static int		client_reconnection(char *data, t_env *e)
{
	char		*ip;
	int			port;
	t_thread	t;

	while (isspace(*data))
		data++;
	if (!*data)
		return (0);
	ip = data;
	while (!isspace(*data) && *data)
		data++;
	if (!*data)
		return (0);
	*data++ = 0;
	if (!(port = ft_atoi(data)))
		return (0);
	t.addr = ip;
	t.port = port;
	t.e = e;
	if ((t.ss = client_connection(ip, port)) == -1)
		return (0);
	perform_command("05 reset !", e);
	wait_command(&t);
	return (1);
}

#define RECONNECT_MSG "enter a new server: <ip> <port>\n"
static void		*wait_command(void *data)
{
	int				ss;
	static char		buff[0xF000];
	int				r;
	t_env			*e;
	_Bool			first;

	ss = ((t_thread *)data)->ss;
	e = ((t_thread *)data)->e;
	while (42)
	{
		first = 1;
		while ((r = read(ss, buff, sizeof(buff) - 1)))
		{
			if (r == -1)
				ft_putstr("can't read data from server !\n");
			if ((r == 0 && first) || r == -1)
				break ;
//			printf("data read from server: %s\n", buff);
			buff[r] = 0;
			parse_commands(buff, e);
			first = 0;
		}
		if (r == 0 || r == -1)
			break ;
	}
	if (r == -1)
		return (NULL);
	close(ss);
	ft_putstr("server connection closed !\n"RECONNECT_MSG);
	while ((r = read(0, buff, sizeof(buff) - 1)) != -1)
	{
		buff[r] = 0;
	   	if (!client_reconnection(buff, e))
			continue ;
		ft_putstr(RECONNECT_MSG);
	}
	ft_putstr("stdin closed !\n");
	return (NULL);
}


void		server_side(int port, char *addr, t_env *e)
{
	pthread_t		t;
	static t_thread	info;

	info.addr = addr;
	info.port = port;
	info.e = e;
	if (!addr)
		ft_exit("invalid ip !\n");
	if ((info.ss = client_connection(addr, port)) == -1)
		ft_exit("can't connect to the specified server !\n");
	get_server_sock(info.ss);
	printf("%i\n", info.ss);
	if (pthread_create(&t, NULL, wait_command, &info) == -1)
		ft_exit("can't initialize threads !\n");
}
