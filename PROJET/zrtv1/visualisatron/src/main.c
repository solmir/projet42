/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:24:18 by alelievr          #+#    #+#             */
/*   Updated: 2016/02/03 17:43:22 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisatron.h"

int64_t		g_keys = 0;
t_mouse		g_mouse = {0, 0, 0, 0, 0};
char		g_key_binding[1024];

static void		init_cam(t_cam *c, t_env *e)
{
	c->angle_x = 0;
	c->angle_y = 0;
	c->angle_z = 0;
	c->pos_x = 0;
	c->pos_y = 0;
	c->pos_z = 0;
	c->zoom = 1.f;
	e->cam = c;
}

static void		init_scene(t_env *e)
{
	e->grid_width = 0;
	e->map = 0;
}

static void		init_key_binding(void)
{
	ft_bzero(g_key_binding, sizeof(g_key_binding));
	g_key_binding[KEY_LEFT] = 1;
	g_key_binding[KEY_RIGHT] = 2;
	g_key_binding[KEY_PLUS] = 3;
	g_key_binding[KEY_MOIN] = 4;
	g_key_binding[KEY_TOP] = 5;
	g_key_binding[KEY_BOTTOM] = 6;
	g_key_binding[KEY_SPACE] = 7;
	g_key_binding[KEY_R] = 8;
	g_key_binding[KEY_Q] = 9;
	g_key_binding[KEY_E] = 10;
	g_key_binding[KEY_NUMP_1] = 11;
	g_key_binding[KEY_NUMP_2] = 12;
	g_key_binding[KEY_NUMP_3] = 13;
	g_key_binding[KEY_NUMP_4] = 14;
	g_key_binding[KEY_NUMP_5] = 15;
	g_key_binding[KEY_NUMP_6] = 16;
	g_key_binding[KEY_NUMP_7] = 17;
	g_key_binding[KEY_NUMP_8] = 18;
	g_key_binding[KEY_NUMP_9] = 19;
}

void		init_msaa()
{
	if (!glfwExtensionSupported("GL_ARB_multisample"))
	{
		printf("GL_ARB_multisample extension not supported\n");

		glfwTerminate();
		exit(EXIT_FAILURE);
	}
}

int			main(int ac, char **av)
{
	GLFWwindow		*win;
	t_env			e;
	t_cam			c;

	init_key_binding();
	init_scene(&e);
	init_cam(&c, &e);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwSetErrorCallback(error_callback);
	if (!(win = glfwCreateWindow(WIN_W, WIN_H, "visualisatron 2000",
					NULL, NULL)))
		ft_exit("failed to open window !");
	e.map = malloc(4096);
	e.player_number = 4;
	e.memory_size = 4096;
	e.grid_width = 64;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 1);
	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
	glfwSetKeyCallback(win, key_callback);
	glfwSetWindowSizeCallback(win, window_size_callback);
	glfwMakeContextCurrent(win);
	glfwSetCursorPosCallback(win, cursor_pos_callback);
	glfwSetMouseButtonCallback(win, mouse_click_callback);
	glfwSetScrollCallback(win, mouse_scroll_callback);
	glfwSwapInterval(1);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glfwShowWindow(win);
	init_msaa();
//	printf("%s\n", glGetString( GL_EXTENSIONS ) );
	while (!glfwWindowShouldClose(win))
		main_loop(win, &e);
	glfwDestroyWindow(win);
	glfwTerminate();
	return (0);
	(void)ac;
	(void)av;
}
