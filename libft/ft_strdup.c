/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:18:51 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:17:08 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *source)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(source) + 1));
	if (dest == NULL)
		return (NULL);
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
