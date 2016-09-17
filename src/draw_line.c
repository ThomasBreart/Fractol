/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:30:53 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 03:31:21 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pixel_put(t_env *e, int x, int y, t_var *var)
{
	unsigned int	int_color;

	if (var->iterations == var->iteration_max)
		int_color = mlx_get_color_value(e->mlx, 0xFFFFFF);
	else
		int_color = var->color_number * var->iterations;
	memcpy(e->data + (y * e->sizeline) + ((e->bpp / 8) * x), &int_color, 3);
}
