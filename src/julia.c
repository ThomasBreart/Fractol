/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 19:18:50 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/12 19:26:27 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(double pixel_x, double pixel_y, t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;
	int			y;

//	x_dim = get_global_id(0);
//	y_dim = get_global_id(1);
	pixel_x = pixel_x / 166 - 3;
	pixel_y = pixel_y / 250 - 2;
//	width = get_global_size(0);
//	int idx = width * y_dim + x_dim;
	c_x = 1;
	c_y = 1;
	y = 0;
	while (y < 100 && z < 4)
	{
		tmp = pixel_x;
		pixel_x = (pixel_x * pixel_x) - (pixel_y * pixel_y) + c_x;
		pixel_y = 2 * tmp * pixel_y + c_y;
		z = (pixel_x * pixel_x) + (pixel_y * pixel_y);
		++y;
	}
	var->iterations = y;;
	return 0;
/*	if (y == 100)
	{
		out[idx] = 0;
	}
	else
	{
		out[idx] = y;
	}*/
}