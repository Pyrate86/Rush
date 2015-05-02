/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:14:22 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/02 06:55:05 by lscopel          ###   ########.fr       */
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

t_color		color(float r, float g, float b, float a)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}

t_square	square(float x, float y, float w, float h)
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
		glColor4f(clr.r, clr.g, clr.b, clr.a);
		glVertex3f(sqr.x, sqr.y, 0.f);
		glVertex3f(sqr.x + sqr.w, sqr.y, 0.f);
		glVertex3f(sqr.x + sqr.w, sqr.y + sqr.h, 0.f);
		glVertex3f(sqr.x, sqr.y + sqr.h, 0.f);
		glEnd();
}

int			main(void)
{
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);
	if (!(glfwInit()))
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(640, 480, "Yggdrasil", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwSetKeyCallback(window, key_callback);

	/* Time since initialization 
	   double time = glfwGetTime(); */

	/* Interval */
	glfwSwapInterval(1);

	glEnable(GL_BLEND) ;
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ;

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	rot = 0;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/*FrameBufferSize */
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		/* Render here */
		//float ratio = width / (float) height;
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glRotatef((float) glfwGetTime() * 50.f * rot, 0.f, 0.f, 1.f);
		draw_square(square(200.f, 150.f, 100.f, 100.f), color(.1f, 1.f, 0.f, 1.f));
		glTranslatef(0.1f * rot, 0.f, 0.f);
		draw_square(square(100.f, 100.f, 100.f, 100.f), color(.5f, 0.f, 1.f, 0.8f));
		draw_brick();
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}
