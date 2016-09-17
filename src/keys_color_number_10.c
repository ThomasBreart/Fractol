/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_color_number_10.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 20:20:00 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 03:38:58 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_number_down_10(void)
{
	t_var	*var;

	var = get_var();
	var->color_number -= 10;
}

void	color_number_up_10(void)
{
	t_var	*var;

	var = get_var();
	var->color_number += 10;
}
