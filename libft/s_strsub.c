/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_strsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 17:13:40 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 17:14:27 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_strsub(char const *s, unsigned int start, size_t len,
														const char *filename)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	if (s == NULL)
		return (NULL);
	tmp = s_strnew(len, filename);
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
