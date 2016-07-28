/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 12:53:22 by tbreart           #+#    #+#             */
/*   Updated: 2016/07/27 22:33:26 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_put(t_env *e, int x, int y, t_coord *tmp)
{
	unsigned int	int_color;

	int_color = mlx_get_color_value(e->mlx, 0xFF0000);
	memcpy(e->data + (y * 1000) + ((e->bpp / 8) * x), &int_color, 3);
}

void	draw_line(t_coord *tmp, t_env *e)
{
	e->tmp_color = 0xFFFFFF;
	draw_line_x(tmp, e);
	draw_line_y(tmp, e);
}
