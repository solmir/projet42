/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:49:25 by alelievr          #+#    #+#             */
/*   Updated: 2016/02/03 19:28:16 by jromagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisatron.h"
#include <math.h>
#define KEY_ACTION(x, y) if (BIT_TEST(g_keys, g_key_binding[x])) y;

static int         mouse_drag(int x, int y, t_env *e)
{
	static int      c = 0;
	static int      old_x = 0;
	static int      old_y = 0;

	if (x >= 0 && y >= 0 && x <= WIN_W && y <= WIN_H)
	{
		if (BIT_TEST(g_mouse.mouse_button, MOUSE_B1) && c > 1)
		{
			e->cam->angle_y += (float)(x - old_x) / 5;
			e->cam->angle_x -= (float)(y - old_y) / 5;
		}
		c++;
	}
	else
		c = 0;
	if ((e->cam->zoom > ZOOM_MAX && g_mouse.yscroll < 0))
		e->cam->zoom *= 1 + (g_mouse.yscroll / 20);
	if ((e->cam->zoom < ZOOM_MIN && g_mouse.yscroll > 0))
		e->cam->zoom *= 1 + (g_mouse.yscroll / 20);
	if (e->cam->zoom > ZOOM_MIN && e->cam->zoom < ZOOM_MAX)
		e->cam->zoom *= 1 + (g_mouse.yscroll / 20);
	old_x = g_mouse.x;
	old_y = g_mouse.y;
	g_mouse.xscroll = 0;
	g_mouse.yscroll = 0;
	return (0);
}

static void	ft_events(t_env *e)
{
	mouse_drag(g_mouse.x, g_mouse.y, e);
	KEY_ACTION(KEY_LEFT, e->cam->angle_z += 2);
	KEY_ACTION(KEY_RIGHT, e->cam->angle_z -= 2);
	KEY_ACTION(KEY_TOP, e->cam->angle_x += 2);
	KEY_ACTION(KEY_BOTTOM, e->cam->angle_x -= 2);
	KEY_ACTION(KEY_PLUS, e->cam->zoom *= 1 + 0.1);
	KEY_ACTION(KEY_MOIN, e->cam->zoom *= 1 - 0.1);
	KEY_ACTION(KEY_Q, e->cam->angle_y += 2);
	KEY_ACTION(KEY_E, e->cam->angle_y -= 2);
	KEY_ACTION(KEY_NUMP_1, (void)0);
	KEY_ACTION(KEY_NUMP_2, (void)0);
	KEY_ACTION(KEY_NUMP_3, (void)0);
}

void		framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	(void)window;
}

float		pixel_to_float_x(const int pix)
{
	return (((float)pix - (WIN_W / 2)) / (WIN_W / 2));
}

float		pixel_to_float_y(const int pix)
{
	return (((float)pix - (WIN_H / 2)) / (WIN_H / 2));
}

void		main_loop(GLFWwindow *win, t_env *e)
{
	int				width;
	int				height;
	int				i;
	static int		frames = 0;

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel (GL_FLAT);

	ft_events(e);
	glfwGetFramebufferSize(win, &width, &height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_STENCIL_TEST);
	glPushMatrix();
	{
		glEnable(GL_ARB_multisample);
		glEnable(GL_MULTISAMPLE);
		glSampleCoverage(0.5, GL_TRUE);
		glLoadIdentity();
		glOrtho(-WIN_W / 2, WIN_W / 2, -WIN_H / 2, WIN_H / 2, -5000, 1000000);
		glRotatef(e->cam->angle_x, 1, 0, 0);
		glRotatef(e->cam->angle_y, 0, 1, 0);
		glRotatef(e->cam->angle_z, 0, 0, 1);
		glTranslatef(e->cam->pos_x, e->cam->pos_y, e->cam->pos_z);
		glScalef(e->cam->zoom, e->cam->zoom, e->cam->zoom);
		gluLookAt(e->cam->pos_x, e->cam->pos_y, e->cam->pos_y,
				GRID_CASE_WIDTH * e->grid_width / 2, -GRID_CASE_WIDTH * e->grid_width / 2, 0,
				0, 1, 0);
		i = -1;



		glColorMaterial ( GL_FRONT_AND_BACK, GL_EMISSION ) ;
		glEnable ( GL_COLOR_MATERIAL ) ;

		GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
		GLfloat mat_shininess[] = { 50.0 };
		GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
		glClearColor (0.0, 0.0, 0.0, 0.0);
		glShadeModel (GL_SMOOTH);

		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_DEPTH_TEST);


		glColor3f(1, 0, 1);
		glutSolidSphere(50, 5000, 5000);
		glTranslatef(120, 0, 0);
		glColor3f(1, 0.5, 0);
		glutSolidSphere(50, 5000, 5000);

		glTranslatef(0, -60, 0);
		glutSolidTeapot(50);
		glTranslatef(0, -120, 0);
		glutSolidTorus(150, 1600, 100, 1000);

/*		glTranslatef(0, -500, 0);
		glDisable(GL_LIGHTING);
		glDisable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		{
			glColor4f(0.7, 0, 0, 1);
			glBegin(GL_QUADS);
			glVertex4f(-10000, 0, -10000, 1);
			glVertex4f(-10000, 0, 10000, 1);
			glVertex4f(10000, 0, 10000, 1);
			glVertex4f(10000, 0, -10000, 1);
			glEnd();
		}
		glEnable(GL_CULL_FACE);
		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);*/

	}
	glPopMatrix();

	glfwSwapBuffers(win);
	glfwPollEvents();
	frames++;
}
