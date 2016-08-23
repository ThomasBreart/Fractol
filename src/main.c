/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 14:32:52 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/23 23:18:41 by tbreart          ###   ########.fr       */
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
	var->win_abs = 700;
	var->win_ord = 700;
	var->iteration_max = 200;
	e->img_ptr = NULL;
}

int	invalid_argument(void)
{
	ft_putendl("usage: ./fractol Mandelbrot | Julia");
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
		var->type = mandelbrot;
	else if (ft_strcmp(av[1], "Julia") == 0)
		var->type = julia;
	else
		return (invalid_argument());
	init(&e);
//	init_();
	display(&e);
	(void)ac;
	(void)av;
	return (0);
}
