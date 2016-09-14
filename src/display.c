/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:34:05 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/14 18:06:57 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_plan(t_var *var)
{
	var->plan_x1 = -2;
	var->plan_x2 = 2;
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
