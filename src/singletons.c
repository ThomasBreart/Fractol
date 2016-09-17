/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 02:07:39 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 02:07:54 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_var		*get_var(void)
{
	static	t_var	var;

	return (&var);
}

t_opencl	*get_opencl(void)
{
	static	t_opencl	opencl;

	return (&opencl);
}
