/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 02:24:16 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/18 02:13:32 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

typedef	struct	s_comp
{
	double		r;
	double		i;
}				t_comp;

t_comp			ft_addcomp(t_comp z1, t_comp z2);
t_comp			ft_mulcomp(t_comp z1, t_comp z2);
t_comp			ft_divcomp(t_comp z1, t_comp z2);
t_comp			ft_subcomp(t_comp z1, t_comp z2);
t_comp			ft_initcomp(double r, double i);
t_comp			ft_mulcompreal(t_comp z1, double k);
t_comp			ft_subcompreal(t_comp z1, double k);

#endif
