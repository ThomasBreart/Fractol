/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 02:08:22 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 15:00:40 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init(t_env *e, t_options *options)
{
	t_var	*var;

	var = get_var();
	var->win_abs = 1000;
	var->win_ord = 1000;
	var->iteration_max = 50;
	var->color_number = 10;
	var->stop_motion_hook = 1;
	var->hud = 0;
	var->fractal_func[0] = mandelbrot;
	var->fractal_func[1] = julia;
	var->fractal_func[2] = burning_ship;
	var->fractal_func[3] = julia_ship;
	var->fractal_func[4] = multibrot;
	var->fractal_func[5] = manowar;
	var->fractal_func[6] = barnsleyj;
	var->fractal_func[7] = spider;
	e->img_ptr = NULL;
	if (is_set_long_option(options, "OpenCL") == 1)
	{
		var->opencl = 1;
		init_opencl(var);
	}
	else
		var->opencl = 0;
}
