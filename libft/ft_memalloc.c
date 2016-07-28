/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 09:27:06 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:10:00 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;
	char	*tmp2;
	size_t	i;

	i = 0;
	tmp = NULL;
	if (size == 0)
		return (NULL);
	tmp = (void*)malloc(size);
	if (tmp == NULL)
		return (NULL);
	tmp2 = tmp;
	while (i < size)
	{
		tmp2[i] = '\0';
		++i;
	}
	return (tmp);
}
