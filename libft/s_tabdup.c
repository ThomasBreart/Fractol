/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tabdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:51:41 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 15:52:35 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**s_tabdup(char **source, const char *filename)
{
	char	**new_tab;
	char	**tmp;

	if (source == NULL)
		return (NULL);
	new_tab = (char**)malloc(sizeof(char*) * (ft_tablen(source) + 1));
	if (new_tab == NULL)
	{
		ft_putstr_fd("Error: fail malloc in ", STDERR_FILENO);
		ft_putstr_fd(filename, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	tmp = new_tab;
	while (*source != NULL)
	{
		*tmp = s_strdup(*source, filename);
		tmp++;
		source++;
	}
	*tmp = NULL;
	return (new_tab);
}
