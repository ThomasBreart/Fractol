/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 20:38:37 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 03:38:25 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_hook_continue(int keycode, t_var *var)
{
	if (keycode == 87)
		color_number_up_100();
	if (keycode == 89)
		color_number_down_1000();
	if (keycode == 91)
		color_number_up_1000();
	if (keycode == 116)
		change_fractal_up();
	if (keycode == 121)
		change_fractal_down();
	if (keycode == 106)
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
	if (keycode == 49)
		stop_motion_hook();
	if (keycode == 53)
	{
		if (var->opencl == 1)
			free_opencl();
		exit(0);
	}
	if (keycode == 69)
		iteration_max_up();
	if (keycode == 78)
		iteration_max_down();
	if (keycode == 83)
		color_number_down_10();
	if (keycode == 84)
		color_number_up_10();
	if (keycode == 86)
		color_number_down_100();
	key_hook_continue(keycode, var);
	expose_hook(e);
	return (0);
}
