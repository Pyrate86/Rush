/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:14:22 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/03 09:00:42 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		move = 0;

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
		move -= 50;
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		move += 50;
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

t_square	square(int x, int y, int w, int h)
{
	t_square	s;
	
	s.x = x;
	s.y = y;
	s.w = w;
	s.h = h;
	return (s);
}

t_coord		coord(int x, int y)
{
	t_coord p;

	p.x = x;
	p.y = y;
	return (p);
}

void		draw_square(t_square sqr, t_color clr)
{
		glBegin(GL_QUADS);
		glColor4f(clr.r, clr.g, clr.b, clr.a);
		glVertex2i(sqr.x, sqr.y);
		glVertex2i(sqr.x + sqr.w, sqr.y);
		glVertex2i(sqr.x + sqr.w, sqr.y + sqr.h);
		glVertex2i(sqr.x, sqr.y + sqr.h);
		glEnd();
}

int			main(void)
{
	GLFWwindow* window;
	t_brick	*b;

	(get_windw())->win_width = 600;
	(get_windw())->win_height = 300;
	glfwSetErrorCallback(error_callback);
	if (!(glfwInit()))
		exit(EXIT_FAILURE);
	window = glfwCreateWindow((get_windw())->win_width, (get_windw())->win_height, "Yggdrasil", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	
	glfwSetKeyCallback(window, key_callback);

	/* Time since initialization 
	   double time = glfwGetTime(); */

	/* Interval */
	glfwSwapInterval(1);

	glEnable(GL_BLEND) ;
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) ;

	move = 0;
	b = NULL;
	t_coord	loop;
	loop.x = 402;
	loop.y = 216;
	t_coord		mov;
	t_square	barre;
	mov.x = -1;
	mov.y = -1;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/*FrameBufferSize */
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);
		(get_windw())->win_width = width;
		(get_windw())->win_height = height;

		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0f, width, height, 0.0f, 0.0f, 1.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.6f * move, 0.f, 0.f);
		// draw_square(square(width / 2 - (width / COLUMNS * 2), height - (height / LINES - 10), width / COLUMNS * 2, height / LINES), color(0.3f, 0.f, 0.85f, 1.f));
		barre = square(width / 2, height - (height / LINES) * 2, width / COLUMNS * 2, (height / LINES));
		draw_square(barre, color(0.3f, 0.f, 0.85f, 1.f));
		barre.x += (0.6f * move);
		glLoadIdentity();
		draw_brick(&b, 0);

		// MOUVEMENT BALLE
		//glTranslatef(0.6f * (float)loop.x, 0.6f * (float)loop.y, 0);
		glTranslatef((float)loop.x, (float)loop.y, 0);
		
		colliboule(&mov, b, barre, &loop);
		
		draw_circle(circle(coord(0, 0), (height / LINES) / 2, 30));
		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}
	//Au changement de level, vider la liste
	//free_bricks(b);
	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}
