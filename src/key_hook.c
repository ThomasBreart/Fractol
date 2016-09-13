/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 20:38:37 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/13 18:59:54 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_env *e)
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
	expose_hook(e);
	return (0);
}
