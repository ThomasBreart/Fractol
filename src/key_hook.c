/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 20:38:37 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/23 20:39:25 by tbreart          ###   ########.fr       */
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
