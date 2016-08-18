/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:34:05 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/18 17:39:06 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_carre(double x)
{
	return (x * x);
}

int		limited_dot(double pixel_x, double pixel_y, t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;

	pixel_x = pixel_x / (var->win_abs / 4) - 3;
	pixel_y = pixel_y / (var->win_ord / 4) - 2;

	c_x = pixel_x;
	c_y = pixel_y;
	var->iterations = 50;
	while (var->iterations > 0)
	{
		tmp = pixel_x;
		pixel_x = ft_carre(pixel_x) - ft_carre(pixel_y) + c_x;
		pixel_y = 2 * tmp * pixel_y + c_y;
		z = ft_carre(pixel_x) + ft_carre(pixel_y);
		if (z > 4)
			return (0);
		--var->iterations; // creer un tmp des iterations
	}
	return (1);
}

void	draw(t_env *e)
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
			if (limited_dot(pixel_x, pixel_y, var) == 1)
				img_pixel_put(e, pixel_x, pixel_y, 1);
			else
				img_pixel_put(e, pixel_x, pixel_y, 0);
			++pixel_x;
		}
		++pixel_y;
	}
}

int		expose_hook(t_env *e)
{
	prepare_draw(e);
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	return (0);
}

void	display(void)
{
	t_env	e;
	t_var	*var;

	e.img_ptr = NULL;
	var = get_var();
	var->win_abs = 1000;
	var->win_ord = 1000;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, var->win_abs, var->win_ord, "Fractol - 42");
	mlx_expose_hook(e.win, expose_hook, &e);
//	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
