/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 09:21:11 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:11:08 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (tmp1[i] == tmp2[i] && i + 1 < n)
		++i;
	return (tmp1[i] - tmp2[i]);
}
