/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 20:29:50 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/19 02:26:11 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				motion_hook(int x, int y, t_env *e)
{
	double	zoom_julia_x;
	double	zoom_julia_y;
	t_var	*var;

	var = get_var();
	if (var->stop_motion_hook == 0)
	{
		zoom_julia_x = var->win_abs / (var->plan_x2 - var->plan_x1);
		zoom_julia_y = var->win_ord / (var->plan_y2 - var->plan_y1);
		var->julia_x = x / zoom_julia_x - var->plan_x2;
		var->julia_y = y / zoom_julia_y - var->plan_y2;
		expose_hook(e);
	}
	return (1);
}

/*
static void		center_zoom(t_var *var, double pixel_x, double pixel_y)
{
	double	ecart_x;
	double	ecart_y;

	ecart_x = pixel_x - (var->plan_x1 + var->plan_x2) / 2;
	ecart_y = pixel_y - (var->plan_y1 + var->plan_y2) / 2;
	var->plan_x1 = var->plan_x1 + ecart_x;
	var->plan_x2 = var->plan_x2 + ecart_x;
	var->plan_y1 = var->plan_y1 + ecart_y;
	var->plan_y2 = var->plan_y2 + ecart_y;
}
*/
int				mouse_hook(int keycode, int x, int y, t_env *e)
{
	double	pixel_x;
	double	pixel_y;
	t_var	*var;

	var = get_var();
	pixel_x = x / var->zoom_x + var->plan_x1;
	pixel_y = y / var->zoom_y + var->plan_y1;
	if (keycode == 5)
		mouse_zoom_up(pixel_x, pixel_y);
	else if (keycode == 1)
	{
//		center_zoom(var, pixel_x, pixel_y);
		mouse_zoom_up(pixel_x, pixel_y);
	}
	else if (var->zoom_x > 50 && var->zoom_y > 50 && keycode == 4)
		mouse_zoom_down(pixel_x, pixel_y);
	else if (var->zoom_x > 50 && var->zoom_y > 50 && keycode == 2)
	{
	//	center_zoom(var, pixel_x, pixel_y);
		mouse_zoom_down(pixel_x, pixel_y);
	}
	expose_hook(e);
	return (0);
}
