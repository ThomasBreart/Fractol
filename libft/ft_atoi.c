/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:27:23 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:05:30 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_issspace(int c)
{
	if ((c == ' ')
			|| (c == '\t')
			|| (c == '\n')
			|| (c == '\v')
			|| (c == '\f')
			|| (c == '\r'))
		return (1);
	return (0);
}

int					ft_atoi(const char *str)
{
	char			*ptr;
	int				i;
	int				neg;
	int				nb;

	ptr = (char*)str;
	i = 0;
	neg = 1;
	nb = 0;
	while (ft_issspace(ptr[i]))
		++i;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			neg = -1;
		++i;
	}
	while (ft_isdigit(ptr[i]))
		nb = nb * 10 + ptr[i++] - '0';
	return (nb * neg);
}
