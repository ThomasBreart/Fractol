/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:02:38 by tbreart           #+#    #+#             */
/*   Updated: 2014/11/14 18:40:31 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;

	tmp = NULL;
	if (dst == NULL || src == NULL)
		return (NULL);
	tmp = (char*)malloc(sizeof(char*) * len);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_strncpy(tmp, src, len);
	dst = (void*)ft_strncpy(dst, tmp, len);
	free(tmp);
	return (dst);
}
