/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 20:07:06 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/15 20:53:02 by tbreart          ###   ########.fr       */
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
	mlx_string_put(e->mlx, e->win, 200, 200, 0xFFFFFF, "prout lol");
	return (0);
}
