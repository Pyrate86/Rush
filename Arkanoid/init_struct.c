/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 04:52:28 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/02 04:53:45 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_color		color(float r, float g, float b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
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
