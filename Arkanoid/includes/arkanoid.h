/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:14:48 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/03 02:05:55 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H
# include <GLFW/glfw3.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

# define BRICK_WIDTH	36
# define BRICK_HEIGHT	16

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_square
{
	int			x;
	int			y;
	int			w;
	int			h;
}					t_square;

typedef struct		s_color
{
	float	r;
	float	g;
	float	b;
	float	a;
}					t_color;

typedef struct		s_brick
{
	float			x;
	float			y;
	float			w;
	float			h;
	int				type;
	t_color			clr;
	struct s_brick	*next;
}					t_brick;

void				draw_brick(t_brick **b, int level);
void				draw_square(t_square sqr, t_color clr);
t_square			square(int x, int y, int w, int h);
t_color				color(float r, float g, float b, float a);
t_coord				coord(int x, int y);

#endif
