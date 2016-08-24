/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_iteration_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 20:21:17 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 20:21:21 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iteration_max_up(void)
{
	t_var	*var;

	var = get_var();
	var->iteration_max += 10;
}

void	iteration_max_down(void)
{
	t_var	*var;

	var = get_var();
	if (var->iteration_max > 0)
		var->iteration_max -= 10;
}
