/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:24:21 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/03 22:24:25 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_windw	*get_windw(void)
{
	static t_windw	*windw;
	if (!windw)
	{
		windw = (t_windw *)ft_memalloc(sizeof(t_windw));
	}
	return (windw);
}

t_boule	*get_boule(void)
{
	static t_boule	*boule;
	if (!boule)
	{
		boule = (t_boule *)ft_memalloc(sizeof(t_boule));
		boule->speed = 2.f;
		boule->size = 1.f;
	}
	return (boule);
}

t_barre	*get_barre(void)
{
	static t_barre	*barre;
	if (!barre)
	{
		barre = (t_barre *)ft_memalloc(sizeof(t_barre));
		barre->speed = 0.6f;
		barre->move = 0;
	}
	return (barre);
}

t_player	*get_player(void)
{
	static t_player	*player;
	if (!player)
	{
		player = (t_player *)ft_memalloc(sizeof(t_player));
		player->level = 0;
		player->life = 2;
		player->score = 0;
	}
	return (player);
}
