/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 14:08:16 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/18 14:33:05 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw2(t_env *e)
{
	int		plan_x1 = -2;
	int		plan_x2 = 2;
	int		plan_y1 = -1;
	int		plan_y2 = 1;

	int		image_x = 500;
	int		image_y = 500;
	int		iteration_max = 50;
	int		zoom_x;
	int		zoom_y;

	zoom_x = image_x / (plan_x2 - plan_x1);
	zoom_y = image_y / (plan_y2 - plan_y1);

	int		x = 0;
	int		y;

	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			int		c_r = x / zoom_x + plan_x1;
			int		c_i = y / zoom_y + plan_y1;
			int		z_r = 0;
			int		z_i = 0;
			int		i = 0;

			while (z_r * z_r + z_i * z_i < 4 && i < iteration_max)
			{
				int		tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				++i;
			}
			if (i == iteration_max)
				mlx_pixel_put(e->mlx, e->win, x, y, 0x000000);
			else
				mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
			++y;
		}
		++x;
	}
}
