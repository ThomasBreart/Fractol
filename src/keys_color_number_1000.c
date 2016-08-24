/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_color_number_1000.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 20:21:51 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 20:22:04 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_number_down_1000(void)
{
	t_var	*var;

	var = get_var();
	var->color_number -= 1000; // check < 0 ?
}

void	color_number_up_1000(void)
{
	t_var	*var;

	var = get_var();
	var->color_number += 1000; // check < 0 ?
}
