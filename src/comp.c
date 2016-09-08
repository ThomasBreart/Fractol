/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 11:46:59 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/08 18:24:33 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_comp		ft_addcomp(t_comp z1, t_comp z2)
{
	z1.r += z2.r;
	z1.i += z2.i;
	return (z1);
}

t_comp		ft_mulcomp(t_comp z1, t_comp z2)
{
	t_comp	tmp;

	tmp.r = z1.r * z2.r - z1.i * z2.i;
	tmp.i = z2.r * z1.i + z1.r * z2.i;
	return (tmp);
}

t_comp		ft_divcomp(t_comp z1, t_comp z2)
{
	t_comp	tmp;

	tmp.r = (z1.r * z2.r + z1.i * z2.i) / (ft_carre(z2.r) + ft_carre(z2.i));
	tmp.i = (z1.i * z2.r - z1.r * z2.i) / (ft_carre(z2.r) + ft_carre(z2.i));
	return (tmp);
}

t_comp		ft_mulcompreal(t_comp z1, double k)
{
	z1.r *= k;
	z1.i *= k;
	return (z1);
}

t_comp		ft_subcomp(t_comp z1, t_comp z2)
{
	z1.r -= z2.r;
	z1.i -= z2.i;
	return (z1);
}

t_comp		ft_initcomp(double r, double i)
{
	t_comp	tmp;

	tmp.r = r;
	tmp.i = i;
	return (tmp);
}

t_comp		ft_subcompreal(t_comp z1, double k)
{
	z1.r -= k;
	z1.i -= k;
	return (z1);
}
