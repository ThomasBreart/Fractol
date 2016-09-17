/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_show_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 23:11:19 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 03:40:01 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_controls(t_env *e, t_var *var, int height_start)
{
	mlx_string_put(e->mlx, e->win, var->win_abs / 20, height_start + 40,
													0xFFFFFF, "Controls :");
	mlx_string_put(e->mlx, e->win, var->win_abs / 20, height_start + 60,
											0xFFFFFF, "Space : mouse on/off");
	mlx_string_put(e->mlx, e->win, var->win_abs / 20, height_start + 80,
								0xFFFFFF, "Page Up/Page Down : change fractal");
	mlx_string_put(e->mlx, e->win, var->win_abs / 20, height_start + 100,
									0xFFFFFF, "Numeric keypad : change color");
	mlx_string_put(e->mlx, e->win, var->win_abs / 20, height_start + 120,
									0xFFFFFF, "+/- keypad : +/- iterations");
	mlx_string_put(e->mlx, e->win, var->win_abs / 20, height_start + 140,
												0xFFFFFF, "M-wheel : +/- zoom");
	mlx_string_put(e->mlx, e->win, var->win_abs / 20, height_start + 160,
														0xFFFFFF, "Esc : quit");
}

void	show_hud(t_env *e)
{
	t_var	*var;
	char	*tmp;
	char	*tmp2;
	int		height_start;

	var = get_var();
	height_start = var->win_ord / 40;
	mlx_string_put(e->mlx, e->win, var->win_abs / 20, height_start,
								0xFFFFFF, "Press 'F16' to show/hide the HUD");
	if (var->hud == 0)
		return ;
	tmp = ft_itoa(var->iteration_max);
	tmp2 = ft_strjoin("Iterations : ", tmp);
	mlx_string_put(e->mlx, e->win, var->win_abs / 20, height_start + 20,
																0xFFFFFF, tmp2);
	free(tmp);
	free(tmp2);
	show_controls(e, var, height_start);
}
