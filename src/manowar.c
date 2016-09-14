/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manowar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 17:55:39 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/14 17:56:16 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		manowar(double pixel_x, double pixel_y, t_var *var)
{
	t_comp		z;
	t_comp		c;
	t_comp		m;
	t_comp		tmp;

	c = ft_initcomp(pixel_x / var->zoom_x + var->plan_x1,
			pixel_y / var->zoom_y + var->plan_y1);
	z = ft_initcomp(0, 0);
	m = z;
	var->iterations = 0;
	while (var->iterations < var->iteration_max)
	{
		tmp = z;
		z = ft_addcomp(ft_addcomp(ft_mulcomp(z, z), m), c);
		if (ft_carre(z.r) + ft_carre(z.i) > 4)
			return (0);
		m = tmp;
		++var->iterations;
	}
	return (0);
}
