/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 05:47:13 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:24:25 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *source, size_t n)
{
	size_t	i;
	char	*dest;
	size_t	len;

	len = ft_strlen(source);
	if (len <= n)
		dest = ft_strnew(len);
	else
		dest = ft_strnew(n);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (source[i] != '\0' && i < n)
	{
		dest[i] = source[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
