/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:32:52 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 15:12:57 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_var	*get_var(void)
{
	static	t_var	var;

	return (&var);
}

void	init(t_env *e)
{
	t_var	*var;

	var = get_var();
	var->win_abs = 500;
	var->win_ord = 500;
	var->iteration_max = 100;
	var->color_number = 10;
	var->stop_motion_hook = 0;
	e->img_ptr = NULL;
}

int	invalid_argument(void)
{
	ft_putendl("usage: ./fractol Mandelbrot | Julia | Burning_ship");
	return (1);
}

int	main(int ac, char **av)
{
	t_env	e;
	t_var	*var;

	var = get_var();
	if (ac > 2)
		return (invalid_argument());
	if (ft_strcmp(av[1], "Mandelbrot") == 0)
		var->fractal_func = mandelbrot;
	else if (ft_strcmp(av[1], "Julia") == 0)
		var->fractal_func = julia;
	else if (ft_strcmp(av[1], "Burning_ship") == 0)
		var->fractal_func = burning_ship;
	else
		return (invalid_argument());
	init(&e);
//	init_();
	display(&e);
	return (0);
}
