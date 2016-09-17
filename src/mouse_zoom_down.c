/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 01:14:19 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/18 01:14:28 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	axis_increase(double axis_limit, const double pixel_coord_axis)
{
	double	increase_gap;
	double	gap_plan_point;

	gap_plan_point = axis_limit - pixel_coord_axis;
	increase_gap = gap_plan_point * 1.5;
	increase_gap = increase_gap - gap_plan_point;
	if (axis_limit < 0)
		axis_limit += increase_gap;
	else
		axis_limit += increase_gap;
	return (axis_limit);
}

void			mouse_zoom_down(const double pixel_x, const double pixel_y)
{
	t_var	*var;

	var = get_var();
	var->plan_x1 = axis_increase(var->plan_x1, pixel_x);
	var->plan_x2 = axis_increase(var->plan_x2, pixel_x);
	var->plan_y1 = axis_increase(var->plan_y1, pixel_y);
	var->plan_y2 = axis_increase(var->plan_y2, pixel_y);
	set_zoom(var);
}
