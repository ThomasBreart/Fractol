/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 20:38:37 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/19 04:55:50 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_hook_continue(int keycode, t_var *var)
{
	if (keycode == KEY_5_NUMPAD)
		color_number_up_100();
	if (keycode == KEY_7_NUMPAD)
		color_number_down_1000();
	if (keycode == KEY_8_NUMPAD)
		color_number_up_1000();
	if (keycode == KEY_PAGE_UP)
		change_fractal_up();
	if (keycode == KEY_PAGE_DOWN)
		change_fractal_down();
	if (keycode == KEY_F16)
	{
		if (var->hud == 0)
			var->hud = 1;
		else
			var->hud = 0;
	}
}

int			key_hook(int keycode, t_env *e)
{
	t_var	*var;

	var = get_var();
	if (keycode == KEY_SPACE)
		stop_motion_hook();
	if (keycode == KEY_ESC)
	{
		if (var->opencl == 1)
			free_opencl();
		exit(0);
	}
	if (keycode == KEY_SUM_NUMPAD)
		iteration_max_up();
	if (keycode == KEY_SUB_NUMPAD)
		iteration_max_down();
	if (keycode == KEY_1_NUMPAD)
		color_number_down_10();
	if (keycode == KEY_2_NUMPAD)
		color_number_up_10();
	if (keycode == KEY_4_NUMPAD)
		color_number_down_100();
	key_hook_continue(keycode, var);
	expose_hook(e);
	return (0);
}
