/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 20:07:06 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 03:34:48 by tbreart          ###   ########.fr       */
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
	e->img_ptr = mlx_new_image(e->mlx, var->win_abs, var->win_ord);
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
			var->fractal_func[var->fractal_index](pixel_x, pixel_y, var);
			img_pixel_put(e, pixel_x, pixel_y, var);
			++pixel_x;
		}
		++pixel_y;
	}
}

int			expose_hook(t_env *e)
{
	t_var	*var;

	var = get_var();
	prepare_draw(e);
	if (var->opencl == 1)
		draw_gpu(e);
	else
		draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	show_hud(e);
	return (0);
}
