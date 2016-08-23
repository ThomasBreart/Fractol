/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:34:05 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/23 19:46:16 by tbreart          ###   ########.fr       */
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

	pixel_x = pixel_x / var->zoom_x + var->plan_x1;
	pixel_y = pixel_y / var->zoom_y + var->plan_y1;
	//pixel_x = pixel_x / (var->win_abs / 4) - var->plan_abs;
	//pixel_y = pixel_y / (var->win_ord / 4) - var->plan_ord;
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

double	axis_reduction(double axis_limit, const double pixel_coord_axis)
{
	double		reduc_gap;
	double		gap_plan_point;

	gap_plan_point = axis_limit - pixel_coord_axis;
	reduc_gap = gap_plan_point / 1.5;
	reduc_gap = gap_plan_point - reduc_gap;
	axis_limit -= reduc_gap;
	return (axis_limit);
}
/*
double	absolu_for_double(double number)
{
	if (number < 0)
		number = number * -1;
	return (number);
}
*/
double	axis_increase(double axis_limit, const double pixel_coord_axis)
{
	double		increase_gap;
	double		gap_plan_point;

	gap_plan_point = axis_limit - pixel_coord_axis;
	increase_gap = gap_plan_point * 1.5;
	increase_gap = increase_gap - gap_plan_point;
	if (axis_limit < 0)
		axis_limit += increase_gap;
	else
		axis_limit += increase_gap;
	return (axis_limit);
}

void	zoom_up(const double pixel_x, const double pixel_y)
{
	t_var	*var;

	var = get_var();
	var->plan_x1 = axis_reduction(var->plan_x1, pixel_x);
	var->plan_x2 = axis_reduction(var->plan_x2, pixel_x);
	var->plan_y1 = axis_reduction(var->plan_y1, pixel_y);
	var->plan_y2 = axis_reduction(var->plan_y2, pixel_y);
	set_zoom(var);
//	printf("x1: %f - x2: %f\ny1: %f - y2: %f\n\n\n", var->plan_x1, var->plan_x2, var->plan_y1, var->plan_y2);
}

void	zoom_down(const double pixel_x, const double pixel_y)
{
	t_var	*var;

	var = get_var();
	var->plan_x1 = axis_increase(var->plan_x1, pixel_x);
	var->plan_x2 = axis_increase(var->plan_x2, pixel_x);
	var->plan_y1 = axis_increase(var->plan_y1, pixel_y);
	var->plan_y2 = axis_increase(var->plan_y2, pixel_y);
	set_zoom(var);
//	printf("x1: %f - x2: %f\ny1: %f - y2: %f\n\n\n", var->plan_x1, var->plan_x2, var->plan_y1, var->plan_y2);
}

void	iterations_max_up(void)
{
	t_var	*var;

	var = get_var();
	var->iteration_max += 10;
}

void	iterations_max_down(void)
{
	t_var	*var;

	var = get_var();
	if (var->iteration_max > 0)
		var->iteration_max -= 10;
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
//	if (keycode == 126)
//		zoom_up();
//	if (keycode == 125)
//		zoom_down();
	if (keycode == 69)
		iterations_max_up();
	if (keycode == 78)
		iterations_max_down();
	expose_hook(e);
	return (0);
}

int		mouse_hook(int keycode, int x, int y, t_env *e)
{
	double	pixel_x;
	double	pixel_y;
	double	ecart_x;
	double	ecart_y;
	t_var	*var;

	var = get_var();
	pixel_x = x / var->zoom_x + var->plan_x1;
	pixel_y = y / var->zoom_y + var->plan_y1;

	ecart_x = pixel_x - (var->plan_x1 + var->plan_x2) / 2;
	ecart_y = pixel_y - (var->plan_y1 + var->plan_y2) / 2;
	var->plan_x1 = var->plan_x1 + ecart_x;
	var->plan_x2 = var->plan_x2 + ecart_x;
	var->plan_y1 = var->plan_y1 + ecart_y;
	var->plan_y2 = var->plan_y2 + ecart_y;
	if (keycode == 1)//5
	{
	zoom_up(pixel_x, pixel_y);
//	printf("x1: %f - x2: %f\ny1: %f - y2: %f\n\n\n", var->plan_x1, var->plan_x2, var->plan_y1, var->plan_y2);
	}
	if (keycode == 2) //4
		zoom_down(pixel_x, pixel_y);
	expose_hook(e);
	return (0);
}

void	display(void)
{
	t_env	e;
	t_var	*var;

	e.img_ptr = NULL;
	var = get_var();
	var->win_abs = 500;
	var->win_ord = 500;
	var->plan_x1 = -3;
	var->plan_x2 = 3;
	var->plan_y1 = -2;
	var->plan_y2 = 2;
	var->iteration_max = 100;
	set_zoom(var);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, var->win_abs, var->win_ord, "Fractol - 42");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	//mlx_hook(var->win_ptr, MOTION_NOTIFY, PTR_MOTION_MASK, ft_motion_hook, var);
	//mlx_hook(var->win_ptr, KEY_PRESS, KEY_PRESS_MASK, ft_key_hook, var);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
