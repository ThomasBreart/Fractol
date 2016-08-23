/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:34:05 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/23 23:11:57 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_carre(double x)
{
	return (x * x);
}

int		mandelbrot(double pixel_x, double pixel_y, t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;

	pixel_x = pixel_x / var->zoom_x + var->plan_x1;
	pixel_y = pixel_y / var->zoom_y + var->plan_y1;
//printf("abs: %f, ord: %f\n", var->plan_abs, var->plan_ord);
	c_x = pixel_x;
	c_y = pixel_y;
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

int		julia(double pixel_x, double pixel_y, t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;

	pixel_x = pixel_x / var->zoom_x + var->plan_x1;
	pixel_y = pixel_y / var->zoom_y + var->plan_y1;
//printf("abs: %f, ord: %f\n", var->plan_abs, var->plan_ord);
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

int		motion_hook(int x, int y, t_env *e)
{
	double	zoom_julia_x;
	double	zoom_julia_y;
	t_var	*var;

	var = get_var();
	zoom_julia_x = var->win_abs / (3 - (-3));
	zoom_julia_y = var->win_ord / (3 - (-3));
	var->julia_x = x / zoom_julia_x - 3;
	var->julia_y = y / zoom_julia_y - 3;
	expose_hook(e);
	return (1);
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
		//	mandelbrot(pixel_x, pixel_y, var);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, motion_hook, e);
//	mlx_hook(e->win, KEY_PRESS, KEY_PRESS_MASK, ft_key_hook, var);
			var->type(pixel_x, pixel_y, var);
			img_pixel_put(e, pixel_x, pixel_y, var);
			++pixel_x;
		}
		++pixel_y;
	}
}

int		expose_hook(t_env *e)
{
	prepare_draw(e);
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

void	set_zoom(t_var *var)
{
	var->zoom_x = var->win_abs / (var->plan_x2 - var->plan_x1);
	var->zoom_y = var->win_ord / (var->plan_y2 - var->plan_y1);
//	printf("zoomx: %f - zoomy: %f\n\n", var->zoom_x, var->zoom_y);
}

/*
double	absolu_for_double(double number)
{
	if (number < 0)
		number = number * -1;
	return (number);
}
*/
void	display(t_env *e)
{
	t_var	*var;

	var = get_var();
	var->plan_x1 = -3;
	var->plan_x2 = 3;
	var->plan_y1 = -2;
	var->plan_y2 = 2;

	var->julia_x = 1;
	var->julia_y = 1;

	set_zoom(var);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, var->win_abs, var->win_ord, "Fractol - 42");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
}
