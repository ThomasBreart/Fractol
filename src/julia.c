/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 19:43:22 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/13 19:03:38 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(double pixel_x, double pixel_y, t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;

	pixel_x = pixel_x / var->zoom_x + var->plan_x1;
	pixel_y = pixel_y / var->zoom_y + var->plan_y1;
	c_x = var->julia_x;
	c_y = var->julia_y;
	var->iterations = 0;
	while (var->iterations < var->iteration_max)
	{
		tmp = pixel_x;
		pixel_x = ft_carre(pixel_x) - ft_carre(pixel_y) + c_x;
		pixel_y = 2 * tmp * pixel_y + c_y;
		z = ft_carre(pixel_x) + ft_carre(pixel_y);
		if (z > 4)
			return (0);
		++var->iterations;
	}
	return (0);
}
