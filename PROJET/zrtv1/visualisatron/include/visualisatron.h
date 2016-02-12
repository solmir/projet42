/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:24:20 by alelievr          #+#    #+#             */
/*   Updated: 2016/02/01 19:58:32 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# define GLFW_INCLUDE_GLU
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <GLUT/glut.h>
# include "libft.h"
# include "glfw3.h"
#include "SOIL.h"
# undef SPACE

# define WIN_W			1920
# define WIN_H			1080
# define SCREEN_MINW	384
# define SCREEN_MINH	216

# define GRID_CASE_WIDTH	20
# define GRID_CASE_PAD		3

# define KEY_LEFT		263
# define KEY_RIGHT		262
# define KEY_SPACE		32
# define KEY_PLUS		334
# define KEY_MOIN		333
# define KEY_M			77
# define KEY_R			82
# define KEY_S			83
# define KEY_V			86
# define KEY_TOP		265
# define KEY_BOTTOM		264
# define KEY_Q			81
# define KEY_E			69
# define KEY_NUMP_1		321
# define KEY_NUMP_2		322
# define KEY_NUMP_3		323
# define KEY_NUMP_4		324
# define KEY_NUMP_5		325
# define KEY_NUMP_6		326
# define KEY_NUMP_7		327
# define KEY_NUMP_8		328
# define KEY_NUMP_9		329

# define CHAR_TOP		"fpmascore02357689"
# define CHAR_BOT		"dluvscoe0235689"
# define CHAR_MID		"fdpaysre2345689"
# define CHAR_TLEFT		"fpmaluyvscore094568"
# define CHAR_TRIGHT	"dpmauyviro01234789"
# define CHAR_BLEFT		"fdpmalccccccuyvcore02689"
# define CHAR_BRIGHT	"dmauvisor01345678"
# define CHAR_COLOR		LGREEN
# define CHAR_PAD		5

#define ZOOM_MAX		6.f
#define ZOOM_MIN		0.153888f

enum			e_mouse_button
{
	MOUSE_B1		= 0,
	MOUSE_B2		= 1,
	MOUSE_B3		= 2,
};

typedef struct	s_coord3f
{
	float	x;
	float	y;
	float	z;
}				t_coord3f;

typedef struct	s_anim
{
	size_t	iter;
	float	b;
	float	c;
	size_t	d;
}				t_anim;

typedef struct	s_cam
{
	double	angle_x;
	double	angle_y;
	double	angle_z;
	double	pos_x;
	double	pos_y;
	double	pos_z;
	double	zoom;
}				t_cam;

typedef struct	s_bmp
{
	int				width;
	int				height;
	unsigned int	image_size;
	unsigned char	*data;
}				t_bmp;

typedef struct	s_env
{
	int		grid_width;
	char	*map;
	t_cam	*cam;
	GLuint	skybox[6];
	GLuint	test;
	int		player_number;
	int		memory_size;
}				t_env;

typedef struct	s_thread
{
	int		port;
	char	*addr;
	int		ss;
	t_env	*e;
}				t_thread;

typedef struct	s_mouse
{
	double	x;
	double	y;
	double	xscroll;
	double	yscroll;
	int		mouse_button;
}				t_mouse;

extern int64_t	g_keys;
extern t_mouse	g_mouse;
extern char		g_key_binding[1024];

/*
**	No categorie:
*/
void			main_loop(GLFWwindow *win, t_env *e);
unsigned char	*load_bmp_file_raw(const char *filename, int *height, int *width);
GLuint			load_bmp_file(const char *filename);
GLuint			LoadTexture(const char *f);
void			try_reconnect(int tryes, void *param);
float			pixel_to_float(const int pix);

/*
**	Controls:
*/
void			key_left(int action);
void			key_right(int action);
void			key_space(int action);

/*
**	CallBacks:
*/
void			error_callback(int error, const char *description);
void			window_size_callback(GLFWwindow *win, int width, int height);
void			key_callback(GLFWwindow *win, int key, int sc, int ac, int md);
void			window_close_callback(GLFWwindow *win);
void			cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
void			mouse_click_callback(GLFWwindow* window, int button, int action, int mods);
void			mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void			framebuffer_size_callback(GLFWwindow* window, int width, int height);

/*
**	Server functions:
*/
void			server_side(int port, char *addr, t_env *e);
int				get_server_sock(int s);
void			close_server_connection(void);

/*
**	Scene:
*/
void			skybox(float w, float h, float d, t_env *e);

#endif
