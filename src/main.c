/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:32:52 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/15 19:41:42 by tbreart          ###   ########.fr       */
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

void		init(t_env *e, t_options *options)
{
	t_var	*var;

	var = get_var();
	var->win_abs = 1000;
	var->win_ord = 1000;
	var->iteration_max = 1000;
	var->color_number = 10;
	var->stop_motion_hook = 1;
	var->fractal_func[0] = mandelbrot;
	var->fractal_func[1] = julia;
	var->fractal_func[2] = burning_ship;
	var->fractal_func[3] = julia_ship;
	var->fractal_func[4] = multibrot;
	var->fractal_func[5] = manowar;
	var->fractal_func[6] = barnsleyj;
	var->fractal_func[7] = spider;
	e->img_ptr = NULL;
	if (is_set_long_option(options, "OpenCL") == 1)
	{
		var->opencl = 1;
		init_opencl(var);
	}
	else
		var->opencl = 0;
}

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
	static t_options options[] =
	{
		{0, "OpenCL", 0},
		{0, NULL, -1}
	};
	return (options);
}

int			main(int ac, char **av)
{
	t_env		e;
	t_var		*var;
	char		**next_av;
	t_options	*options;
	var = get_var();

	options = set_options();
	if (ac > 3 || options_manager(av, &next_av, options) == -1 || *next_av == NULL)
		return (invalid_argument());
	if (ft_strcmp(*next_av, "Mandelbrot") == 0)
		var->fractal_index = 0;
	else if (ft_strcmp(*next_av, "Julia") == 0)
		var->fractal_index = 1;
	else if (ft_strcmp(*next_av, "Burning_ship") == 0)
		var->fractal_index = 2;
	else if (ft_strcmp(*next_av, "Julia_ship") == 0)
		var->fractal_index = 3;
	else if (ft_strcmp(*next_av, "Multibrot") == 0)
		var->fractal_index = 4;
	else if (ft_strcmp(*next_av, "Manowar") == 0)
		var->fractal_index = 5;
	else if (ft_strcmp(*next_av, "Barnsleyj") == 0)
		var->fractal_index = 6;
	else if (ft_strcmp(*next_av, "Spider") == 0)
		var->fractal_index = 7;
	else
		return (invalid_argument());
	init(&e, options);
	display(&e);
	return (0);
}
