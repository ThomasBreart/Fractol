/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:51:39 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:21:24 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (s != NULL && f != NULL)
	{
		tmp = ft_strnew(ft_strlen(s));
		if (tmp == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			tmp[i] = f(i, s[i]);
			++i;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
