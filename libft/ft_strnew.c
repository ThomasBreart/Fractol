/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:53:53 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:24:58 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = NULL;
	tmp = (char*)malloc(sizeof(*tmp) * (size + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < size + 1)
	{
		tmp[i] = '\0';
		++i;
	}
	return (tmp);
}
