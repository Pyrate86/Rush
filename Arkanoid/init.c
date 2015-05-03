/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 21:45:44 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/03 22:06:15 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	init_level(t_brick *b)
{
	t_brick *tmp;

	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
		tmp = NULL;
	}
	//b = NULL;
	//draw_brick(&b, (get_player())->level);
}