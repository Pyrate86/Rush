/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 22:46:27 by ghilbert          #+#    #+#             */
/*   Updated: 2015/05/03 22:09:51 by ghilbert         ###   ########.fr       */
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

t_color	color_type(int t)
{
	t_color c;
	if (t < 5 && t > 0)
		c = color(0.f, 1.f, 0.f, 1.f);
	else if (t < 9)
		c = color(1.f, 1.f, 0.f, 1.f);
	else if (t < 13)
		c = color(1.f, 0.f, 0.f, 1.f);
	else if (t < 17)
		c = color(0.4f, 0.3f, 0.6f, 1.f);
	else
		c = color(0.2f, 0.2f, 0.3f, 1.f);
	return (c);
}

void	add_brick(t_brick **b, t_coord p, char buff)
{
	t_brick	*new;

	new = (t_brick *)malloc(sizeof(t_brick));
	if (new)
	{
		new->brick.w = COLUMNS;
		new->brick.h = LINES;
		new->brick.x = p.x;
		new->brick.y = p.y;
		new->type = buff - ' ';
		new->clr = color_type(new->type);
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
		if (b->type > 0)
		draw_square(square(b->brick.x * ((get_windw())->win_width / b->brick.w), b->brick.y * ((get_windw())->win_height / b->brick.h), (get_windw())->win_width / b->brick.w, (get_windw())->win_height / b->brick.h), color_type(b->type));
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