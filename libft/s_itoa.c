/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 17:17:21 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 17:17:23 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int				len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		++len;
	while (n != 0)
	{
		n = n / 10;
		++len;
	}
	return (len);
}

char		*s_itoa(int n, const char *filename)
{
	char			*tmp;
	int				a;
	int				b;

	b = ft_get_size(n);
	tmp = s_strnew(b, filename);
	a = 1;
	if (n < 0)
	{
		a = -1;
		tmp[0] = '-';
	}
	if (n == 0)
		tmp[0] = '0';
	if (b > 0)
		--b;
	while (n != 0)
	{
		tmp[b] = a * (n % 10) + '0';
		n = n / 10;
		--b;
	}
	return (tmp);
}
