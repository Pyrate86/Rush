/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:57:12 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/03 23:06:47 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	loose_life(t_coord *mov, t_coord *loop)
{
	int	lines;

	lines = ((get_windw())->win_height / LINES);
	loop->x = (get_windw())->win_width / 2;
	loop->y = 300 - (lines * 2) - (lines / 4);
	mov->x = -1;
	mov->y = -1;
	(get_player())->life -= 1;
	if ((get_player())->life < 1)
		exit(0);
}

void		collit(t_square bl, t_square br, t_brick *b, t_norme p)
{
	if (collision(bl, br) == 1 || collibrick(b, bl) == 1)
		p.mov->x = -p.mov->x;
	else
	{
		p.loop->x++;
		if ((bl.x + bl.w) > ((get_windw())->win_width))
			p.mov->x = -p.mov->x;
	}
}

void		collib(t_square bl, t_square br, t_brick *b, t_norme p)
{
	if (collision(bl, br) == 3 || collibrick(b, bl) == 3)
		p.mov->x = -p.mov->x;
	else
	{
		p.loop->x--;
		if (bl.x < 0)
			p.mov->x = -p.mov->x;
	}
}

void		collil(t_square bl, t_square br, t_brick *b, t_norme p)
{
	if (collision(bl, br) == 2 || collibrick(b, bl) == 2)
		p.mov->y = -p.mov->y;
	else
	{
		p.loop->y++;
		if ((bl.y + bl.h) > ((get_windw())->win_height))
			loose_life(p.mov, p.loop);
	}
}

void		collir(t_square bl, t_square br, t_brick *b, t_norme p)
{
	if (collision(bl, br) == 4 || collibrick(b, bl) == 4)
		p.mov->y = -p.mov->y;
	else
	{
		p.loop->y--;
		if (bl.y < 0)
			p.mov->y = -p.mov->y;
	}
}
