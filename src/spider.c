/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 18:05:13 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/14 18:05:44 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		spider(double pixel_x, double pixel_y, t_var *var)
{
	t_comp		z;
	t_comp		c;

	z = ft_initcomp(pixel_x / var->zoom_x + var->plan_x1,
					pixel_y / var->zoom_y + var->plan_y1);
	c = z;
	var->iterations = 0;
	while (var->iterations < var->iteration_max)
	{
		z = ft_addcomp(ft_mulcomp(z, z), c);
		c.r /= 2;
		c.i /= 2;
		c = ft_addcomp(c, z);
		if (ft_carre(z.r) + ft_carre(z.i) > 4)
			return (0);
		++var->iterations;
	}
	return (0);
}
