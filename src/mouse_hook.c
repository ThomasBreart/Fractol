/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 20:29:50 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/23 20:37:37 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
