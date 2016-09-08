/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:34:05 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/08 18:44:26 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
/*
int		plop(double pixel_x, double pixel_y, t_var *var)
{
	double		z;

	pixel_x = pixel_x / var->zoom_x + var->plan_x1;
	pixel_y = pixel_y / var->zoom_y + var->plan_y1;
	var->iterations = 0;
	while (var->iterations < var->iteration_max)
	{
		if (pixel_y > 0.5)
		{
			pixel_x = (2 * pixel_x);
			pixel_y = 2 * pixel_y - 1;
		}
		else if (pixel_x > 0.5)
		{
			pixel_x = (2 * pixel_x - 1);
			pixel_y = 2 * pixel_y;
		}
		else
		{
			pixel_x = 2 * pixel_x;
			pixel_y = 2 * pixel_y;
		}
		z = (ft_carre(pixel_x) + ft_carre(pixel_y));
		if (z > 4)
			return (0);
		++var->iterations;
	}
	return (0);
}*/
/*
int		plop(double pixel_x, double pixel_y, t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp1;
	double		i;
	double		tmp2;
	double		tmp;


	pixel_x = pixel_x / var->zoom_x + var->plan_x1;
	pixel_y = pixel_y / var->zoom_y + var->plan_y1;
	c_x = pixel_x;
	c_y = pixel_y;
	var->iterations = 0;
	z = 0;
	i = 1;
	tmp1 = 0;
	tmp2 = 0;
	while (var->iterations < var->iteration_max)
	{
		tmp = pixel_x;
		pixel_x = ft_carre(pixel_x) - ft_carre(pixel_y) + c_x;
		if (i == 1)
			pixel_y = 2 * tmp * pixel_y + c_y * tmp1;
		else
			pixel_y = 2 * tmp * pixel_y + c_y * tmp2;
		z = ft_carre(pixel_x) + ft_carre(pixel_y);
		if (z > 4)
			return (0);
		if (i == 1)
		{
			tmp1 = z;
			i = 2;
		}
		else
		{
			tmp2 = z;
			i = 1;
		}
		++var->iterations;
	}
	return (0);
}
*/
int		plop(double pixel_x, double pixel_y, t_var *var)
{
	double		z;
	t_comp		c;
	t_comp		c2;
	t_comp		tmp;
	t_comp		x;
	t_comp		h;

	x = ft_initcomp(pixel_x / var->zoom_x + var->plan_x1,
									pixel_y / var->zoom_y + var->plan_y1);
	c = x;
	c.r -= 1;
	c2 = x;
	c2.r -= 2;
	tmp = ft_initcomp(0, 0);
	var->iterations = 0;
	while (var->iterations < var->iteration_max)
	{
		x = ft_addcomp(ft_mulcomp(tmp, tmp), c);
		x = ft_mulcomp(x, x);
		h = ft_addcomp(ft_mulcompreal(tmp, 2), c2);
		h = ft_mulcomp(h, h);
		tmp = ft_divcomp(x, h);
		z = (ft_carre(tmp.r) + ft_carre(tmp.i));
		if (z > 2)
			return (0);
		++var->iterations;
	}
	return (0);
}
void	init_plan(t_var *var)
{
	var->plan_x1 = -3;
	var->plan_x2 = 3;
	var->plan_y1 = -2;
	var->plan_y2 = 2;

	var->julia_x = 1;
	var->julia_y = 1;
}

void	set_zoom(t_var *var)
{
	var->zoom_x = var->win_abs / (var->plan_x2 - var->plan_x1);
	var->zoom_y = var->win_ord / (var->plan_y2 - var->plan_y1);
}

void	display(t_env *e)
{
	t_var	*var;

	var = get_var();
	init_plan(var);
	set_zoom(var);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, var->win_abs, var->win_ord, "Fractol - 42");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, motion_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
}
