/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colliboule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 08:21:40 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/03 10:48:34 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	collibarre(t_square barre)
{
	if ((barre.x + barre.w) >= (get_windw())->win_width)
		ft_putendl("trop facho");
	if (barre.x <= 0)
		ft_putendl("trop coco");
		
}

int		collision(t_square boule, t_square barre)
{
	if((barre.x >= boule.x + boule.w)      // trop à droite
	|| (barre.x + barre.w <= boule.x) // trop à gauche
	|| (barre.y >= boule.y + boule.h) // trop en bas
	|| (barre.y + barre.h <= boule.y))  // trop en haut
          return (0);
	
	if (boule.x <= barre.x)
		return (1);
	else if ((boule.x + boule.w) >= (barre.x + barre.w))
		return (3);
	else if (boule.y <= barre.y)
		return (2);
	return (4);
}


void	colliboule(t_coord *mov, t_brick *b, t_square barre, t_coord *loop)
{
	collibarre(barre);
	t_square	boule;
	
	boule.w = ((get_windw())->win_height / LINES);
	boule.h = boule.w;
	boule.x = loop->x - (boule.w / 2);
	boule.y = loop->y - (boule.h / 2);
	(void)barre;
	(void)b;
	if (mov->x == 1)
	{
		if (collision(boule, barre) == 1)
			mov->x = -mov->x;
		else
		{
			loop->x++;
			if ((boule.x + boule.w) > ((get_windw())->win_width))
				mov->x = -mov->x;
		}
	}
	else
	{
		if (collision(boule, barre) == 3)
			mov->x = -mov->x;
		else
		{
			loop->x--;
			if (boule.x < 0)
				mov->x = -mov->x;
		}
	}
	if (mov->y == 1)
	{
		if (collision(boule, barre) == 2)
			mov->y = -mov->y;
		else
		{
			loop->y++;
			if ((boule.y + boule.h) > ((get_windw())->win_height))
				mov->y = -mov->y;
		}
	}
	else
	{
		if (collision(boule, barre) == 4)
			mov->y = -mov->y;
		else
		{
			loop->y--;
			if (boule.y < 0)
				mov->y = -mov->y;
		}
	}
}