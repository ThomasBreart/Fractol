/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_set_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 03:43:33 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/18 02:11:22 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if (options->long_name != NULL &&
							ft_strcmp(option_name, options->long_name) == 0)
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
