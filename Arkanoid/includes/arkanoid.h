/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:14:48 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/02 06:03:29 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H
# include "../glfw/include/GLFW/glfw3.h"
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"


typedef struct		s_square
{
	float			x;
	float			y;
	float			w;
	float			h;
}					t_square;

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;
	float			a;
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

#endif

