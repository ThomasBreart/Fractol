/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_stop_motion_hook.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 20:15:32 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/15 19:20:28 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	stop_motion_hook(void)
{
	t_var	*var;

	var = get_var();
	if (var->stop_motion_hook == 0)
		var->stop_motion_hook = 1;
	else
		var->stop_motion_hook = 0;
}
