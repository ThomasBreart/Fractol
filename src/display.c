/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:34:05 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/18 14:33:09 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		dot_bornay(double x, double y)
{
	double		z;
	double		tmpx;
	double		tmpy;
	int			iterations;
	double		tmp;

	x = x / 250 - 2;
	y = y / 250 - 2;
	tmpx = x;
	tmpy = y;
//	z = (x * x) - (y * y);
	iterations = 100;
	while (iterations > 0)
	{
		tmp = x;
		x = 2 * x * y + tmpx;
		y = (-1) * (tmp * tmp) + (y * y) + tmpy;
	//	z = (z * z) + ((x * x) - (y * y));
	//	z = z * z + (0.32 * 0.32) - (0.043 * 0.043);
		z = (x * x) + (y * y);
		if (z > 4) // 4 ou 2
			return (0);
		--iterations;
	}
	return (1);
}

void	draw(t_env *e)
{
	double		x;
	double		y;

	x = 0;
	y = 0;
	while (y < 1000)
	{
		x = 0;
		while (x < 1000)
		{
			//»·img_pixel_put(e, x, y, tmp);
			if (dot_bornay(x, y) == 1)
				mlx_pixel_put(e->mlx, e->win, x, y, 0x000000);
			else
				mlx_pixel_put(e->mlx, e->win, x, y, 0xFF0000);
			++x;
		}
		++y;
	}
}

int		expose_hook(t_env *e)
{
	//prepare_draw(e);
	mlx_clear_window(e->mlx, e->win);
	//draw(e);
	draw2(e);
	//mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

void	display(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "Fractol - 42");
	mlx_expose_hook(e.win, expose_hook, &e);
//	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
