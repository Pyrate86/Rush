/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:14:48 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/03 08:24:13 by ghilbert         ###   ########.fr       */
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
# include <math.h>
# include <errno.h>

# define LINES	36
# define COLUMNS	16
// # define WIN_WIDTH		612
// # define WIN_HEIGHT		480

typedef struct 		s_windw
{
	int				win_width;
	int				win_height;
}					t_windw;

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

typedef struct		s_circle
{
	int				nbface;
	float			radius;
	float			theta;
	float			cosinus;
	float			sinus;
	t_coord			center;
}					t_circle;

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
void				draw_circle(t_circle c);
void				colliboule(t_coord *mov, t_brick *b, t_square barre, t_coord *loop);
t_square			square(int x, int y, int w, int h);
t_circle			circle(t_coord center, float radius, int nbface);
t_color				color(float r, float g, float b, float a);
t_coord				coord(int x, int y);
t_windw				*get_windw(void);

#endif