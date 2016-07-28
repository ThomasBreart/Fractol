/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:15:17 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:09:35 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(long long n)
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

char		*ft_lltoa(long long n)
{
	char			*tmp;
	int				a;
	int				b;

	b = ft_get_size(n);
	if ((tmp = ft_strnew(b)) == NULL)
		return (NULL);
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
