/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 22:46:27 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/03 00:54:35 by ghilbert         ###   ########.fr       */
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
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, tmp[i]);
		i++;
	}
	path = ft_strjoin(path, "/../levels/");
	path = ft_strjoin(path, ft_itoa(lvl));
	path = ft_strjoin(path, ".ygg");
	return (path);
}

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
		new->clr = color(0.5f * (new->type % 3), 0.5f * (new->type % 4), 0.5f * (new->type % 2), 1.f);
			new->next = *b;
		*b = new;
	}
}

void	creat_list(t_brick **b, int lvl)
{
	char	*path;
	char buff;
	int ret;
	int fd;
	t_coord	p;

	path = get_path(lvl);
	fd = open(path, O_RDONLY);
	p.x = 0;
	p.y = 0;
	while((ret = read(fd, &buff, 1)) > 0)
	{
		if (buff == ' ')
			p.x++;
		else if (buff == '\n')
		{
			p.x = 0;
			p.y++;
		}
		else
		{
			add_brick(b, p, buff);
			p.x++;
		}
	}
	close(fd);
}

void	print_brick(t_brick *b)
{
	while (b != NULL)
	{
		draw_square(square(b->x, b->y, b->w, b->h), b->clr);
		b = b->next;
	}
}

void	draw_brick(t_brick **b, int level)
{
	if (!*b)
	{
		creat_list(b, level);	
	}
	print_brick(*b);
}