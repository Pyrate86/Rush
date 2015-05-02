/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_callback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscopel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 02:22:51 by lscopel           #+#    #+#             */
/*   Updated: 2015/05/02 02:23:19 by lscopel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void error_callback(int error, const char* description)
{
	(void)error;
	ft_putendl_fd(description, 2);
}
