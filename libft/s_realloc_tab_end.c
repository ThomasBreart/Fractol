/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_realloc_tab_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 17:52:59 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 17:53:02 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** new_index a du etre malloc avant
*/

char	**s_realloc_tab_end(char **source, char *new_index,
											const char *filename)
{
	char	**new_tab;
	char	**tmp;
	char	**tmp_source;

	if (source == NULL && new_index == NULL)
		return (NULL);
	if (source == NULL)
		new_tab = (char**)s_memalloc(sizeof(char*) * 2, filename);
	else
		new_tab = (char**)s_memalloc(sizeof(char*) * (ft_tablen(source) + 2),
																	filename);
	tmp = new_tab;
	tmp_source = source;
	while (source != NULL && *source != NULL)
	{
		*tmp = s_strdup(*source, filename);
		++tmp;
		++source;
	}
	*tmp = new_index;
	++tmp;
	*tmp = NULL;
	free_double_tab(tmp_source);
	return (new_tab);
}
