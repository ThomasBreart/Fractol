/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_color_number_100.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 20:22:27 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 20:22:43 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_number_down_100(void)
{
	t_var	*var;

	var = get_var();
	var->color_number -= 100; // check < 0 ?
}

void	color_number_up_100(void)
{
	t_var	*var;

	var = get_var();
	var->color_number += 100; // check < 0 ?
}
