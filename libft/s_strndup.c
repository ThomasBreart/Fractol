/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_strndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:44:30 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 18:27:40 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_strndup(char *source, size_t n, const char *filename)
{
	size_t	i;
	char	*dest;
	size_t	len;

	len = ft_strlen(source);
	if (len <= n)
		dest = ft_strnew(len);
	else
		dest = ft_strnew(n);
	if (dest == NULL)
	{
		ft_putstr_fd("Error: fail malloc in ", STDERR_FILENO);
		ft_putendl_fd(filename, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (source[i] != '\0' && i < n)
	{
		dest[i] = source[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
