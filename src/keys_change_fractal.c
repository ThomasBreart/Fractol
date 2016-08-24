/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_change_fractal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 20:10:37 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 20:11:37 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_fractal_up(void)
{
	t_var	*var;

	var = get_var();
	if (var->fractal_index == 4)
		var->fractal_index = 0;
	else
		++var->fractal_index;
	init_plan(var);
	set_zoom(var);
}

void	change_fractal_down(void)
{
	t_var	*var;

	var = get_var();
	if (var->fractal_index == 0)
		var->fractal_index = 4;
	else
		--var->fractal_index;
	init_plan(var);
	set_zoom(var);
}
