/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:42:28 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 18:27:17 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*s_strdup(char *source, const char *filename)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(source) + 1));
	if (dest == NULL)
	{
		ft_putstr_fd("Error: fail malloc in ", STDERR_FILENO);
		ft_putendl_fd(filename, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
