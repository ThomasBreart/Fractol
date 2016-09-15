/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 19:28:31 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/15 19:37:05 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_set_short_option(t_options *options, const char option_name)
{
	while (options->set != -1)
	{
		if (options->short_name != 0 && option_name == options->short_name)
		{
			if (options->set == 1)
				return (1);
			else
				return (0);
		}
		++options;
	}
	return (-1);
}

int		is_set_long_option(t_options *options, const char *option_name)
{
	while (options->set != -1)
	{
		if (options->long_name != NULL && ft_strcmp(option_name, options->long_name) == 0)
		{
			if (options->set == 1)
				return (1);
			else
				return (0);
		}
		++options;
	}
	return (-1);
}

int		is_an_option(const char *av)
{
	if (av[0] == '-' && av[1] == '-')
		return (2);
	else if (av[0] == '-')
		return (1);
	return (0);
}

int		good_long_option(const char *av, t_options *options)
{
	while (options->set != -1)
	{
		if (options->long_name != NULL && ft_strcmp(options->long_name, av + 2) == 0)///
		{
			options->set = 1;
			return (1);
		}
		++options;
	}
	return (0);
}

int		good_short_option(const char *av, t_options *options)
{
	while (options->set != -1)
	{
		if (options->short_name != 0 && ft_strchr(av, options->short_name) != NULL)
		{
			options->set = 1;
			return (1);
		}
		++options;
	}
	return (0);
}

int		options_manager(char **av, char ***next_av, t_options *options)
{
	int		type_opt;

	++av;
	while (*av != NULL)
	{
		if ((type_opt = is_an_option(*av)))
		{
			if (type_opt == 1)
				type_opt = good_short_option(*av, options);
			else if (type_opt == 2)
				type_opt = good_long_option(*av, options);
			if (type_opt == 0)
				return (-1);
		}
		else
			break ;
		++av;
	}
	*next_av = av;
	return (1);
}
