/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 20:29:50 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 19:55:31 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		motion_hook(int x, int y, t_env *e)
{
	double	zoom_julia_x;
	double	zoom_julia_y;
	t_var	*var;

	var = get_var();
	if (var->stop_motion_hook == 0)
	{
		zoom_julia_x = var->win_abs / (3 - (-3));
		zoom_julia_y = var->win_ord / (3 - (-3));
		var->julia_x = x / zoom_julia_x - 3;
		var->julia_y = y / zoom_julia_y - 3;
		expose_hook(e);
	}
	return (1);
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
		mouse_zoom_up(pixel_x, pixel_y);
	if (keycode == 2) //4
		mouse_zoom_down(pixel_x, pixel_y);
	expose_hook(e);
	return (0);
}
