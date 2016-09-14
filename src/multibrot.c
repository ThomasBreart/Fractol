/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 17:52:19 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/14 17:54:09 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		multibrot(double pixel_x, double pixel_y, t_var *var)
{
	t_comp		z;
	t_comp		c;

	z = ft_initcomp(pixel_x / var->zoom_x + var->plan_x1,
					pixel_y / var->zoom_y + var->plan_y1);
	c = z;
	var->iterations = 0;
	while (var->iterations < var->iteration_max)
	{
		z = ft_addcomp(ft_mulcomp(ft_mulcomp(ft_mulcomp(z, z), z), z), c);
		if (ft_carre(z.r) + ft_carre(z.i) > 4)
			return (0);
		++var->iterations;
	}
	return (0);
}
