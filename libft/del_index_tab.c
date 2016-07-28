/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_index_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 05:59:55 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 14:04:26 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	realloc tab en supprimant index
*/

char	**del_index_tab(char **taab, int index)
{
	char	**new;
	int		len;
	int		i;
	int		j;

	len = ft_tablen(taab) - 1;
	new = (char**)malloc(sizeof(char *) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (taab[i] != NULL)
	{
		if (i != index)
		{
			new[j] = ft_strdup(taab[i]);
			++j;
		}
		++i;
	}
	new[j] = NULL;
	free_double_tab(taab);
	return (new);
}
