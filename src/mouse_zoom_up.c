/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 19:50:56 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 19:52:00 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	axis_reduction(double axis_limit, const double pixel_coord_axis)
{
	double	reduc_gap;
	double	gap_plan_point;

	gap_plan_point = axis_limit - pixel_coord_axis;
	reduc_gap = gap_plan_point / 1.5;
	reduc_gap = gap_plan_point - reduc_gap;
	axis_limit -= reduc_gap;
	return (axis_limit);
}

void			mouse_zoom_up(const double pixel_x, const double pixel_y)
{
	t_var	*var;

	var = get_var();
	var->plan_x1 = axis_reduction(var->plan_x1, pixel_x);
	var->plan_x2 = axis_reduction(var->plan_x2, pixel_x);
	var->plan_y1 = axis_reduction(var->plan_y1, pixel_y);
	var->plan_y2 = axis_reduction(var->plan_y2, pixel_y);
	set_zoom(var);
}
