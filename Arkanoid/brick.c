/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 05:45:02 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/02 18:50:08 by lscopel          ###   ########.fr       */
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

void		add_brick(char buff, t_coord p, t_brick **b)
{
	t_brick	*new;
	
	new = (t_brick *)malloc(sizeof(t_brick));
	new->x = p.x * BRICK_WIDTH;
	new->y = p.y * BRICK_HEIGHT;
	new->w = BRICK_WIDTH;
	new->h = BRICK_HEIGHT;
	new->type = buff - ' ';
	if (b == NULL)
		new->next = NULL;
	else
		new->next = *b;
	new->clr = color(0.3f * ((int)new->type % 10), 1.f, 0.3f * new->type / 10, 1.f);
	*b = new;
	//draw_square(square(new->x, new->y, new->w, new->h), new->clr);

}

t_brick		**create_list(int level, t_brick **b)
{
	char	*path;
	char buff;
	int ret;
	int fd;
	t_coord	p;
	t_brick	**tmp;

	tmp = b;
	path = get_path(level);
	fd = open(path, O_RDONLY);
	p.x = 0;
	p.y = 0;
	while((ret = read(fd, &buff, 1)) > 0)
	{
		ft_putchar(buff);
		if (buff == ' ')
			p.x++;
		else if (buff == '\n')
		{
			p.x = 0;
			p.y++;
		}
		else
		{
			add_brick(buff, p, tmp);
			p.x++;
		}
	}
	close(fd);
	return (tmp);
}

t_brick		**draw_brick(int level, t_brick **b)
{
	t_brick	*tmp;

	tmp = (t_brick *)malloc(sizeof(t_brick));
	tmp->x = 0;
	tmp->y = 0;
	tmp->w = 100;
	tmp->h = 100;
	tmp->type = 0;
	tmp->clr = color(1.0f, 0.f, 0.f, 1.f);
	tmp->next = NULL;
	if (!b)
	{
		ft_putendl("VIDE");
		b = &tmp;
		//b = NULL;
		b = create_list(level, b);
	}
/*
	t_brick **c = b;
ft_putnbr((*c)->x);
	while (*c)
	{
		draw_square(square((*c)->x, (*c)->y, (*c)->w, (*c)->h), (*c)->clr);
		*c = (*c)->next;
	}
//*/
//*
	ft_putstr("\e[92m");
	ft_putnbr((*b)->x);
	ft_putendl("\e[0m");
	while (*b)
	{
		draw_square(square((*b)->x, (*b)->y, (*b)->w, (*b)->h), (*b)->clr);
		*b = (*b)->next;
	}
//*/
	return (b);
}
