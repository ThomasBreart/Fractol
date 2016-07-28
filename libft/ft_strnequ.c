/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:14:02 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:24:44 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	if ((i < n) && (s2[i] != '\0'))
		return (0);
	return (1);
}
