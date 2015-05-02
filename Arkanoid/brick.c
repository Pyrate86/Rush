/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 22:46:27 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/02 23:01:01 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	add_brick(t_brick **b, int tmp, int x)
{
	t_brick	*new;

	new = (t_brick *)malloc(sizeof(t_brick));
	if (new)
	{
		new->type = tmp;
		new->x = x * BRICK_WIDTH;
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

	if (!*b)
	{
		while (i < 4)
		{
			add_brick(b, level - i, i);
			i++;
		}
	}
	print_brick(*b);

}