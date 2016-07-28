/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <tbreart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:53:53 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 18:27:54 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** faire un put_nbr_unsigned_long pour pouvoir afficher __LINE__
*/

char	*s_strnew(size_t size, const char *filename)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	tmp = (char*)malloc(sizeof(*tmp) * (size + 1));
	if (tmp == NULL)
	{
		ft_putstr_fd("Error: fail malloc in ", STDERR_FILENO);
		ft_putendl_fd(filename, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < size + 1)
	{
		tmp[i] = '\0';
		++i;
	}
	return (tmp);
}
