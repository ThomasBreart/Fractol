/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:32:52 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 03:41:38 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			invalid_argument(void)
{
	ft_putstr("usage: ./fractol");
	ft_putstr(" [--OpenCL]");
	ft_putstr(" Mandelbrot | Julia | Burning_ship | Julia_ship | Multibrot");
	ft_putendl(" | Manowar | Barnsleyj | Spider");
	return (-1);
}

t_options	*set_options(void)
{
	static t_options options[] = {
		{0, "OpenCL", 0},
		{0, NULL, -1}};

	return (options);
}

int			find_fractal_type(const char *next_av, int *fractal_index)
{
	if (ft_strcmp(next_av, "Mandelbrot") == 0)
		*fractal_index = 0;
	else if (ft_strcmp(next_av, "Julia") == 0)
		*fractal_index = 1;
	else if (ft_strcmp(next_av, "Burning_ship") == 0)
		*fractal_index = 2;
	else if (ft_strcmp(next_av, "Julia_ship") == 0)
		*fractal_index = 3;
	else if (ft_strcmp(next_av, "Multibrot") == 0)
		*fractal_index = 4;
	else if (ft_strcmp(next_av, "Manowar") == 0)
		*fractal_index = 5;
	else if (ft_strcmp(next_av, "Barnsleyj") == 0)
		*fractal_index = 6;
	else if (ft_strcmp(next_av, "Spider") == 0)
		*fractal_index = 7;
	else
		return (-1);
	return (1);
}

int			main(int ac, char **av)
{
	t_env		e;
	t_var		*var;
	char		**next_av;
	t_options	*options;

	var = get_var();
	options = set_options();
	if (ac > 3 || options_manager(av, &next_av, options) == -1)
		return (invalid_argument());
	if (*next_av == NULL ||
						find_fractal_type(*next_av, &var->fractal_index) == -1)
		return (invalid_argument());
	init(&e, options);
	display(&e);
	return (0);
}
