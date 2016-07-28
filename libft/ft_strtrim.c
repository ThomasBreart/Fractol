/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:41:53 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:30:02 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	int		counter;
	size_t	i;
	int		j;

	if (s == NULL)
		return (NULL);
	tmp = (char*)s;
	i = 0;
	j = 0;
	counter = 0;
	while (tmp[i] == ' ' || tmp[i] == '\n' || tmp[i] == '\t')
	{
		++counter;
		++i;
	}
	if (i == (ft_strlen(s)))
		return ("\0");
	j = ft_strlen(s) + 1;
	while (tmp[--j - 1] == ' ' || tmp[j - 1] == '\n' || tmp[j - 1] == '\t')
		++counter;
	tmp = ft_strsub(tmp, i, (ft_strlen(s) - counter));
	return (tmp);
}
