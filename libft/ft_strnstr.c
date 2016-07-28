/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:11:38 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:25:25 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	int			j;
	size_t		a;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[j])
		{
			a = i;
			while (s1[a] == s2[j] && s1[a] != '\0' && s2[j] != '\0' && a < n)
			{
				++a;
				++j;
			}
			if (s2[j] == '\0')
				return ((char*)(s1 + i));
			j = 0;
		}
		++i;
	}
	return (NULL);
}
