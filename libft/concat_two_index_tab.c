/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_two_index_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 00:20:10 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 13:59:30 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**create_new_tab(char **taab, int index1, int index2, char *concat)
{
	char	**new;
	int		len;
	int		i;
	int		j;

	len = ft_tablen(taab) - 1;
	if ((new = (char**)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (taab[i] != NULL)
	{
		if (i == index1)
			new[j] = concat;
		else if (i != index2)
		{
			new[j] = ft_strdup(taab[i]);
			++j;
		}
		++i;
	}
	new[i] = NULL;
	return (new);
}

/*
**	realloc le tab avec index1 et index2 de concat a lemplacement de index1
*/

char		**concat_two_index_tab(char **taab, int index1, int index2)
{
	char	**new;
	char	*concat;

	concat = ft_strnew(ft_strlen(taab[index1]) + ft_strlen(taab[index2]));
	if (concat == NULL)
		return (NULL);
	ft_strcat(concat, taab[index1]);
	ft_strcat(concat, taab[index2]);
	new = create_new_tab(taab, index1, index2, concat);
	if (new == NULL)
	{
		free(concat);
		return (NULL);
	}
	free_double_tab(taab);
	return (new);
}
