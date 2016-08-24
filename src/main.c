/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:32:52 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 20:02:52 by tbreart          ###   ########.fr       */
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

	var->fractal_func[0] = mandelbrot;
	var->fractal_func[1] = julia;
	var->fractal_func[2] = burning_ship;
	var->fractal_func[3] = julia_ship;
	var->fractal_func[4] = plop;
	e->img_ptr = NULL;
}

int	invalid_argument(void)
{
	ft_putendl("usage: ./fractol Mandelbrot | Julia | Burning_ship | Julia_ship");
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
		var->fractal_index = 0;
	else if (ft_strcmp(av[1], "Julia") == 0)
		var->fractal_index = 1;
	else if (ft_strcmp(av[1], "Burning_ship") == 0)
		var->fractal_index = 2;
	else if (ft_strcmp(av[1], "Julia_ship") == 0)
		var->fractal_index = 3;
	else if (ft_strcmp(av[1], "plop") == 0)
		var->fractal_index = 4;
	else
		return (invalid_argument());
	init(&e);
	display(&e);
	return (0);
}
