/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 03:00:37 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/03 05:02:14 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_circle	circle(t_coord center, float radius, int nbface)
{
	t_circle	c;

	c.center = center;
	c.radius = radius;
	c.nbface = nbface;
	c.theta = 2 * M_PI / (float)c.nbface;
	c.cosinus = cosf(c.theta);
	c.sinus = sinf(c.theta);
	return (c);
}

void		draw_circle(t_circle c)
{
	float	tmp;
	float	x;
	float	y;
	int		i;

	x = c.radius;
	y = 0;
	i = 0;
	glBegin(GL_TRIANGLE_FAN);
	while (i < c.nbface)
	{
		glColor4f(1.f, .5f, 0.1f, 1.f);
		glVertex2f(x + c.center.x, y + c.center.y);
		tmp = x;
		x = c.cosinus * x - c.sinus * y;
		y = c.sinus * tmp + c.cosinus * y;
		i++;
	}
	glEnd();
}
