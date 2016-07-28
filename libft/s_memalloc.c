/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_memalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 14:48:23 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 18:26:52 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*s_memalloc(size_t size, const char *filename)
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
	{
		ft_putstr_fd("Error: fail malloc in ", STDERR_FILENO);
		ft_putendl_fd(filename, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	tmp2 = tmp;
	while (i < size)
	{
		tmp2[i] = '\0';
		++i;
	}
	return (tmp);
}
