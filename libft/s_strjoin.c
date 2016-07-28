/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 17:26:13 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 17:26:41 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_strjoin(char const *s1, char const *s2, const char *filename)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = s_strnew(ft_strlen(s1) + ft_strlen(s2), filename);
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
