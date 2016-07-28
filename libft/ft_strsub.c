/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:00:26 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:29:23 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	if (s == NULL)
		return (NULL);
	tmp = ft_strnew(len);
	if (tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start];
		++start;
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}
