/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 19:28:31 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/18 02:11:48 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_an_option(const char *av)
{
	if (av[0] == '-' && av[1] == '-')
		return (2);
	else if (av[0] == '-')
		return (1);
	return (0);
}

static int		good_long_option(const char *av, t_options *options)
{
	while (options->set != -1)
	{
		if (options->long_name != NULL &&
									ft_strcmp(options->long_name, av + 2) == 0)
		{
			options->set = 1;
			return (1);
		}
		++options;
	}
	return (0);
}

static int		good_short_option(const char *av, t_options *options)
{
	while (options->set != -1)
	{
		if (options->short_name != 0 &&
									ft_strchr(av, options->short_name) != NULL)
		{
			options->set = 1;
			return (1);
		}
		++options;
	}
	return (0);
}

int				options_manager(char **av, char ***next_av, t_options *options)
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
