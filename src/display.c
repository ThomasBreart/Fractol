/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:34:05 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 20:06:49 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		plop(double pixel_x, double pixel_y, t_var *var)
{
	double		z;

	pixel_x = pixel_x / var->zoom_x + var->plan_x1;
	pixel_y = pixel_y / var->zoom_y + var->plan_y1;
	var->iterations = 0;
	while (var->iterations < var->iteration_max)
	{
		if (pixel_y > 0.5)
		{
			pixel_x = (2 * pixel_x);
			pixel_y = 2 * pixel_y - 1;
		}
		else if (pixel_x > 0.5)
		{
			pixel_x = (2 * pixel_x - 1);
			pixel_y = 2 * pixel_y;
		}
		else
		{
			pixel_x = 2 * pixel_x;
			pixel_y = 2 * pixel_y;
		}
		z = (ft_carre(pixel_x) + ft_carre(pixel_y));
		if (z > 4)
			return (0);
		++var->iterations;
	}
	return (0);
}

void	init_plan(t_var *var)
{
	var->plan_x1 = -3;
	var->plan_x2 = 3;
	var->plan_y1 = -2;
	var->plan_y2 = 2;

	var->julia_x = 1;
	var->julia_y = 1;
}

void	set_zoom(t_var *var)
{
	var->zoom_x = var->win_abs / (var->plan_x2 - var->plan_x1);
	var->zoom_y = var->win_ord / (var->plan_y2 - var->plan_y1);
}

void	display(t_env *e)
{
	t_var	*var;

	var = get_var();
	init_plan(var);
	set_zoom(var);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, var->win_abs, var->win_ord, "Fractol - 42");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, motion_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
}
