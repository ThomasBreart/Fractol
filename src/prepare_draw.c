/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 18:27:28 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/20 14:56:12 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	prepare_draw(t_env *e)
{
	int		endian;

	mlx_clear_window(e->mlx, e->win);
	//if (e->check_img != 0)
	if (e->img_ptr != NULL)
		mlx_destroy_image(e->mlx, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx, 1000, 1000); ///
	e->data = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->sizeline, &endian);
//	printf("endian: %d\nsizeline: %d\nbpp: %d\n", endian, e->sizeline, e->bpp);
}
