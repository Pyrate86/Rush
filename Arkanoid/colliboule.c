/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colliboule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 08:21:40 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/03 23:04:27 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	collibarre(t_square barre)
{
	int	width;

	width = (get_windw())->win_width;
	if ((barre.x + barre.w) >= width - width / COLUMNS)
		(get_barre())->move = (width / 2) + width / COLUMNS;
	if (barre.x <= width / COLUMNS)
		(get_barre())->move = -(width / 2) - barre.w;
}

int		collision(t_square boule, t_square barre)
{
	if ((barre.x >= boule.x + boule.w)
	|| (barre.x + barre.w <= boule.x)
	|| (barre.y >= boule.y + boule.h)
	|| (barre.y + barre.h <= boule.y))
		return (0);
	if (boule.x <= barre.x)
		return (1);
	else if ((boule.x + boule.w) >= (barre.x + barre.w))
		return (3);
	else if (boule.y <= barre.y)
		return (2);
	return (4);
}

int		collibrick(t_brick *b, t_square boule)
{
	int			ret;
	int			width;
	int			height;
	t_square	brick;

	while (b)
	{
		width = (get_windw())->win_width / b->brick.w;
		height = (get_windw())->win_height / b->brick.h;
		brick = square(b->brick.x * width, b->brick.y * height, width, height);
		ret = collision(boule, brick);
		if (ret && b->type > 0)
		{
			if (b->type >= 1 && b->type <= 13)
			{
				b->type -= 1;
				(get_player())->score += 1;
				if (next_level(b))
					exit (0);
			}
			return (ret);
		}
		b = b->next;
	}
	return (0);
}

t_norme	norme(t_coord *a, t_coord *b)
{
	t_norme	n;

	n.mov = a;
	n.loop = b;
	return (n);
}

void	colliboule(t_coord *mov, t_brick *b, t_square barre, t_coord *loop)
{
	t_square	boule;

	boule.w = ((get_windw())->win_height / LINES);
	boule.h = boule.w;
	boule.x = loop->x - (boule.w / 2);
	boule.y = loop->y - (boule.h / 2);
	collibarre(barre);
	if (mov->x == 1)
		collit(boule, barre, b, norme(mov, loop));
	else
		collib(boule, barre, b, norme(mov, loop));
	if (mov->y == 1)
		collil(boule, barre, b, norme(mov, loop));
	else
		collir(boule, barre, b, norme(mov, loop));
}
