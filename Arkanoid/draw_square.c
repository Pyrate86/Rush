/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:30:26 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/03 22:31:05 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

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
