/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 20:46:24 by alelievr          #+#    #+#             */
/*   Updated: 2016/02/01 18:55:45 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisatron.h"

void			error_callback(int error, const char *description)
{
	ft_putendl_fd(description, 2);
	(void)error;
}

void			key_callback(GLFWwindow *window, int key, int scancode,
		int action, int mods)
{
	printf("key = %i - action = %i\n", key, action);
	if (key < 1024)
		if (g_key_binding[key])
		{
			if (action)
				BIT_ON(g_keys, g_key_binding[key]);
			else
				BIT_OFF(g_keys, g_key_binding[key]);
		}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwDestroyWindow(window);
		close_server_connection();
		ft_putstr("Bye !\n");
		exit(0);
	}
	(void)mods;
	(void)scancode;
}

void			window_size_callback(GLFWwindow *win, int width, int height)
{
	(void)width;
	(void)height;
	(void)win;
}

void			cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
{
	g_mouse.x = xpos;
	g_mouse.y = ypos;
	(void)window;
}

void			mouse_click_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action)
		BIT_ON(g_mouse.mouse_button, button);
	else
		BIT_OFF(g_mouse.mouse_button, button);
	(void)window;
	(void)mods;
}

void			mouse_scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	g_mouse.xscroll = xoffset;
	g_mouse.yscroll = yoffset;
	(void)window;
}
