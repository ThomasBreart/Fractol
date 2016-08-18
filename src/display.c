/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:34:05 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/18 21:21:30 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_carre(double x)
{
	return (x * x);
}

int		limited_dot(double pixel_x, double pixel_y, t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;

	pixel_x = pixel_x / (var->win_abs / 4) - var->plan_abs;
	pixel_y = pixel_y / (var->win_ord / 4) - var->plan_ord;
//printf("abs: %f, ord: %f\n", var->plan_abs, var->plan_ord);
	c_x = pixel_x;
	c_y = pixel_y;
	var->iterations = 0;
	var->iteration_max = 100; ///
	while (var->iterations < var->iteration_max)
	{
		tmp = pixel_x;
		pixel_x = ft_carre(pixel_x) - ft_carre(pixel_y) + c_x;
		pixel_y = 2 * tmp * pixel_y + c_y;
		z = ft_carre(pixel_x) + ft_carre(pixel_y);
		if (z > 4)
			return (0);
		++var->iterations; // creer un tmp des iterations
	}
	return (0);
}

void	draw(t_env *e)
{
	double		pixel_x;
	double		pixel_y;
	t_var		*var;

	var = get_var();
	pixel_x = 0;
	pixel_y = 0;
	while (pixel_y < var->win_ord)
	{
		pixel_x = 0;
		while (pixel_x < var->win_abs)
		{
			limited_dot(pixel_x, pixel_y, var);
			img_pixel_put(e, pixel_x, pixel_y, var);
			++pixel_x;
		}
		++pixel_y;
	}
}

int		expose_hook(t_env *e)
{
//	prepare_draw(e);
	draw2(e);
//	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

void	zoom_up(void)
{
	t_var	*var;

	var = get_var();
	var->plan_abs = var->plan_abs - 0.5;
	var->plan_ord = var->plan_ord - 0.5;
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		zoom_up();
//	if (keycode == 125)
//		zoom_down();
	expose_hook(e);
	return (0);
}

void	display(void)
{
	t_env	e;
	t_var	*var;

	e.img_ptr = NULL;
	var = get_var();
	var->win_abs = 1000;
	var->win_ord = 1000;
	var->plan_abs = 3;
	var->plan_ord = 2;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, var->win_abs, var->win_ord, "Fractol - 42");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
