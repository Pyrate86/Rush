/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:14:48 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/03 23:03:57 by ghilbert         ###   ########.fr       */
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

typedef struct		s_player
{
	int				life;
	int				score;
	int				level;
}					t_player;

typedef struct 		s_barre
{
	float			speed;
	int				move;
}					t_barre;

typedef struct 		s_boule
{
	float			speed;
	float			size;
}					t_boule;

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

typedef struct		s_norme
{
	t_coord			*mov;
	t_coord			*loop;
}					t_norme;

typedef struct		s_brick
{
	t_square		brick;
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
t_barre				*get_barre(void);
t_player			*get_player(void);
void				init_level(t_brick *b);


int					collibrick(t_brick *b, t_square boule);
int					collision(t_square boule, t_square barre);
void				collit(t_square bl, t_square br, t_brick *b, t_norme p);
void				collib(t_square bl, t_square br, t_brick *b, t_norme p);
void				collil(t_square bl, t_square br, t_brick *b, t_norme p);
void				collir(t_square bl, t_square br, t_brick *b, t_norme p);

int					next_level(t_brick *b);


#endif