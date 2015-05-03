/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colliboule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 08:21:40 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/03 22:09:28 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	collibarre(t_square barre)
{
	if ((barre.x + barre.w) >= (get_windw())->win_width - (get_windw())->win_width / COLUMNS)
		{
			(get_barre())->move = ((get_windw())->win_width / 2) + (get_windw())->win_width / COLUMNS;
		}
	if (barre.x <= (get_windw())->win_width / COLUMNS)
		{
			(get_barre())->move = -((get_windw())->win_width / 2) - barre.w;
		}
		
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

int		next_level(t_brick *b)
{
	while (b)
	{
		if (b->type >= 1 && b->type <= 13)
			return (0);
		b = b->next;
	}
	return (1);
}

int		collibrick(t_brick *b, t_square boule)
{
	int ret;

	ret = 0;
	while (b)
	{
		ret = collision(boule, square(b->brick.x * ((get_windw())->win_width / b->brick.w), b->brick.y * ((get_windw())->win_height / b->brick.h), (get_windw())->win_width / b->brick.w, (get_windw())->win_height / b->brick.h));
		if (ret && b->type > 0)
		{
			if (b->type >= 1 && b->type <= 13)
			{
				b->type -= 1;
				(get_player())->score += 1;
				if (next_level(b))
				{
					
					// (get_player())->level += 1;
					// if ((get_player())->level > 2)
						exit (0);
					// init_level(b);
				}
			}
			return (ret);
		}
		b = b->next;
	}
	return (0);
}

void	loose_life(t_coord *mov, t_coord *loop)
{
	loop->x = (get_windw())->win_width / 2;
	loop->y = 300 - (((get_windw())->win_height / LINES) * 2) - (((get_windw())->win_height / LINES) / 4);
	mov->x = -1;
	mov->y = -1;
	(get_player())->life -= 1;
	if ((get_player())->life < 1)
		exit(0);
}

void	colliboule(t_coord *mov, t_brick *b, t_square barre, t_coord *loop)
{
	t_square	boule;
	
	boule.w = ((get_windw())->win_height / LINES);
	boule.h = boule.w;
	boule.x = loop->x - (boule.w / 2);
	boule.y = loop->y - (boule.h / 2);
	(void)b;


	collibarre(barre);
	if (mov->x == 1)
	{
		if (collision(boule, barre) == 1 || collibrick(b, boule) == 1)
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
		if (collision(boule, barre) == 3 || collibrick(b, boule) == 3)
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
		if (collision(boule, barre) == 2 || collibrick(b, boule) == 2)
			mov->y = -mov->y;
		else
		{
			loop->y++;
			if ((boule.y + boule.h) > ((get_windw())->win_height))
				loose_life(mov, loop);//mov->y = -mov->y;
		}
	}
	else
	{
		if (collision(boule, barre) == 4 || collibrick(b, boule) == 4)
			mov->y = -mov->y;
		else
		{
			loop->y--;
			if (boule.y < 0)
				mov->y = -mov->y;
		}
	}
}