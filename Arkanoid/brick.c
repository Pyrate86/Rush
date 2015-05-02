/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 22:46:27 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/02 23:45:58 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	add_brick(t_brick **b, t_coord p, char buff)
{
	t_brick	*new;

	new = (t_brick *)malloc(sizeof(t_brick));
	if (new)
	{
		new->x = p.x * BRICK_WIDTH;
		new->y = p.y * BRICK_HEIGHT;
		new->w = BRICK_WIDTH;
		new->h = BRICK_HEIGHT;
		new->type = buff - ' ';
		new->clr = color(0x10 * ((int)new->type % 10), 0x7F, 0x25 * new->type / 10, 255);
			new->next = *b;
		*b = new;
	}
}

void	print_brick(t_brick *b)
{
	ft_putendl("#### ####");
	while (b != NULL)
	{
		ft_putstr("\e[93m");
		ft_putchar(b->type + ' ');
		ft_putstr("\e[0m=>\e[93m");
		ft_putnbr(b->x);
		ft_putendl("\e[0m");
		b = b->next;
	}
	ft_putendl("#### ####");
}

void	draw_brick(t_brick **b, int level)
{
	int i = 0;
	t_coord = 
	if (!*b)
	{
		while (i < 4)
		{
			add_brick(b, );
			i++;
		}
	print_brick(*b);
	}

}