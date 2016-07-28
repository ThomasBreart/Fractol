/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:15:20 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:20:36 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (s != NULL && f != NULL)
	{
		tmp = ft_strnew(ft_strlen(s));
		if (tmp == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			tmp[i] = f(s[i]);
			++i;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}
