/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:45:02 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/02 06:38:09 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

char		*get_path(int lvl)
{
	char	*path;
	char	**tmp;
	int		i;
	path = getenv("_");
	tmp = ft_strsplit(path, '/');
	i = 0;
	path = tmp[0][0] == '.' ? tmp[i++] : "";
	while (tmp[i + 1])
	{
		path = ft_strjoin(path, '/');
		path = ft_strjoin(path, tmp[i]);
		i++;
	}
	path = ft_strjoin(path, "../levels/");
	path = ft_strjoin(path, ft_itoa(lvl));
	path = ft_strjoin(path, ".ygg");
	return (path);
}

t_brick		*create_list(int level)
{
	t_brick *b;
	char	*path;
	path = get_path(level);

	return (b)
}

void		draw_brick(int level)
{
	t_brick	*b;
	b = NULL;
	b = create_list(level);
	while (b)
	{
		draw_square(square(b->x, b->y, b->w, b->h), b->clr);
		b = b->next;
	}

}
