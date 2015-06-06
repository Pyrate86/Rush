/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:14:22 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/03 23:25:07 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void kcb(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_LEFT
			&& (action == GLFW_PRESS || action == GLFW_REPEAT))
		(get_barre())->move -= 50;
	if (key == GLFW_KEY_RIGHT
			&& (action == GLFW_PRESS || action == GLFW_REPEAT))
		(get_barre())->move += 50;
}

void		make_init(GLFWwindow *window)
{
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, kcb);
	glfwSwapInterval(1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void		destroy_init(GLFWwindow *window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void		init_ball(t_coord *loop, t_coord *mov, t_square barre, t_brick *b, int height)
{
		glTranslatef((float)loop->x, (float)loop->y, 0);
		colliboule(mov, b, barre, loop);
		draw_circle(circle(coord(0, 0), (height / LINES) / 2, 30));
}

int			main(void)
{
	GLFWwindow	*window;
	t_brick		*b;
	t_coord		loop;
	t_coord		mov;
	t_square	barre;

	(get_windw())->win_width = 600;
	(get_windw())->win_height = 300;
	b = NULL;
	glfwSetErrorCallback(error_cb);
	if (!(glfwInit()))
		exit(EXIT_FAILURE);
	window = glfwCreateWindow((get_windw())->win_width, (get_windw())->win_height, "Yggdrasil", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return (-1);
	}
	make_init(window);
	loop.x = (get_windw())->win_width / 2;
	loop.y = 300 - (((get_windw())->win_height / LINES) * 2) - (((get_windw())->win_height / LINES) / 4);
	mov.x = -1;
	mov.y = -1;
	get_player();
	while (!glfwWindowShouldClose(window))
	{
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
		glTranslatef(0.6f * (get_barre())->move, 0.f, 0.f);
		barre = square(width / 2 - width / COLUMNS, height - (height / LINES) * 2, width / COLUMNS * 2, (height / LINES));
		draw_square(barre, color(0.3f, 0.f, 0.85f, 1.f));
		barre.x += (0.6f * (get_barre())->move);
		glLoadIdentity();
		draw_brick(&b, (get_player())->level);
		init_ball(&loop, &mov, barre, b, height);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	destroy_init(window);
	return (0);
}
