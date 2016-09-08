/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 20:07:06 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/08 09:55:06 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	prepare_draw(t_env *e)
{
	int		endian;
	t_var	*var;

	var = get_var();
	mlx_clear_window(e->mlx, e->win);
	if (e->img_ptr != NULL)
		mlx_destroy_image(e->mlx, e->img_ptr);
	e->img_ptr = mlx_new_image(e->mlx, var->win_abs, var->win_ord); ///
	e->data = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->sizeline, &endian);
}

static void	draw(t_env *e)
{
	double		pixel_x;
	double		pixel_y;
	t_var		*var;

	var = get_var();
	pixel_x = 0;
	pixel_y = 0;
	while (pixel_y < var->win_ord)
	{
		pixel_x = 0;
		while (pixel_x < var->win_abs)
		{
			//	mlx_hook(e->win, KEY_PRESS, KEY_PRESS_MASK, ft_key_hook, var);
			var->fractal_func[var->fractal_index](pixel_x, pixel_y, var);
			img_pixel_put(e, pixel_x, pixel_y, var);
			++pixel_x;
		}
		++pixel_y;
	}
}
/*
static void	draw_gpu(t_env *e)
{
	t_var	*var;
	int		prob_size;

	var = get_var();
	// alloc mem
	double * tpixel_x = (double*)malloc(var->win_abs * sizeof(double));
	double * tpixel_y = (double*)malloc(var->win_ord * sizeof(double));
	double * tzoom_y = (double*)malloc(var->win_ord * sizeof(double));
	double * tzoom_x = (double*)malloc(var->win_abs * sizeof(double));
	double * tplan_x1 = (double*)malloc(var->win_abs * sizeof(double));
	double * tplan_y1 = (double*)malloc(var->win_ord * sizeof(double));
	double * tplan_y1 = (double*)malloc(var->win_ord * sizeof(double));
	double * tplan_y1 = (double*)malloc(var->win_ord * sizeof(double));
	double * tplan_y1 = (double*)malloc(var->win_ord * sizeof(double));
	double * tplan_y1 = (double*)malloc(var->win_ord * sizeof(double));
	//prob_size = var->win_abs * var->win_ord;
	
}
*/
int			expose_hook(t_env *e)
{
	prepare_draw(e);
	draw(e);
	//draw_gpu(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}
