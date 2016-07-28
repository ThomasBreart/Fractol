/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 10:32:25 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:19:26 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	chain1;
	size_t	chain2;
	size_t	n;

	n = size;
	chain1 = ft_strlen(dst);
	chain2 = ft_strlen(src);
	while (*dst && n)
	{
		++dst;
		--n;
	}
	if (!n)
		return (size + chain2);
	while (*src && n > 1)
	{
		*++dst = *++src;
		--n;
	}
	*dst = '\0';
	return (chain1 + chain2);
}
