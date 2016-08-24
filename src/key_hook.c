/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 20:38:37 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 15:07:22 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	color_number_down_1000(void)
{
	t_var	*var;

	var = get_var();
	var->color_number -= 1000; // check < 0 ?
}

void	color_number_up_1000(void)
{
	t_var	*var;

	var = get_var();
	var->color_number += 1000; // check < 0 ?
}

void	color_number_down_100(void)
{
	t_var	*var;

	var = get_var();
	var->color_number -= 100; // check < 0 ?
}

void	color_number_up_100(void)
{
	t_var	*var;

	var = get_var();
	var->color_number += 100; // check < 0 ?
}

void	color_number_down_10(void)
{
	t_var	*var;

	var = get_var();
	var->color_number -= 10; // check < 0 ?
}

void	color_number_up_10(void)
{
	t_var	*var;

	var = get_var();
	var->color_number += 10; // check < 0 ?
}

void	stop_motion_hook(void)
{
	t_var	*var;

	var = get_var();
	if (var->stop_motion_hook == 0)
		var->stop_motion_hook = 1;
	else
		var->stop_motion_hook = 0;
}

int		key_hook(int keycode, t_env *e)
{
	t_var	*var;

	var = get_var();
	if (keycode == 53)
		exit(0);
//	if (keycode == 126)
//		zoom_up();
//	if (keycode == 125)
//		zoom_down();
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
	if (keycode == 69)
		iterations_max_up();
	if (keycode == 78)
		iterations_max_down();
	if (keycode == 49)
		stop_motion_hook();
	expose_hook(e);
	return (0);
}
