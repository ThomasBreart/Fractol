/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsleyj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 18:04:41 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/14 18:04:43 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		barnsleyj(double pixel_x, double pixel_y, t_var *var)
{
	t_comp	z;
	t_comp	c;

	c = ft_initcomp(var->julia_x, var->julia_y);
	z = ft_initcomp(pixel_x / var->zoom_x + var->plan_x1,
					pixel_y / var->zoom_y + var->plan_y1);
	var->iterations = 0;
	while (var->iterations < var->iteration_max)
	{
		if (z.r > 0)
		{
			z.r -= 1;
			z = ft_mulcomp(z, c);
		}
		else
		{
			z.r += 1;
			z = ft_mulcomp(z, c);
		}
		if ((z.r * z.r + z.i * z.i) > 4)
			return (0);
		++var->iterations;
	}
	return (0);
}
