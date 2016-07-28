/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:23:35 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:18:26 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (tmp == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp[j] = s1[i];
		++i;
		++j;
	}
	i = -1;
	while (s2[++i] != '\0')
	{
		tmp[j] = s2[i];
		++j;
	}
	tmp[j] = '\0';
	return (tmp);
}
