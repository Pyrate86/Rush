/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:14:22 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/02 23:40:00 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		rot = 0;

void error_callback(int error, const char* description)
{
	(void)error;
	ft_putendl_fd(description, 2);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		rot -= 50;
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		rot += 50;
}

t_color		color(int r, int g, int b, int a)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}

t_square	square(int x, int y, int w, int h)
{
	t_square	s;
	
	s.x = x;
	s.y = y;
	s.w = w;
	s.h = h;
	return (s);
}

void		draw_square(t_square sqr, t_color clr)
{
		glBegin(GL_QUADS);
		glColor4ui(clr.r, clr.g, clr.b, clr.a);
		glVertex2i(sqr.x, sqr.y);
		glVertex2i(sqr.x + sqr.w, sqr.y);
		glVertex2i(sqr.x + sqr.w, sqr.y + sqr.h);
		glVertex2i(sqr.x, sqr.y + sqr.h);
		glEnd();
}

int			main(void)
{
	GLFWwindow* window;
	t_brick *b;

	glfwSetErrorCallback(error_callback);

	if (!(glfwInit()))
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(640, 480, "Yggdrasil", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);

	/* Interval */
	glfwSwapInterval(1);

	b = NULL;

	while (!glfwWindowShouldClose(window))
	{
		/*FrameBufferSize */

		glClear(GL_COLOR_BUFFER_BIT);

		draw_brick(&b, 0);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();

	return (0);
}
