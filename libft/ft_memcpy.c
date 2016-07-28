/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:00:50 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:11:23 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	char			*tmp2;

	i = 0;
	tmp1 = (unsigned char*)dest;
	tmp2 = (char*)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		++i;
	}
	return (dest);
}
