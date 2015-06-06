/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:26:56 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/03 22:27:54 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

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
