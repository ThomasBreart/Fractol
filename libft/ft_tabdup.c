/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 10:44:17 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 13:58:46 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **source)
{
	char	**new_tab;
	char	**tmp;

	if (source == NULL)
		return (NULL);
	new_tab = (char**)malloc(sizeof(char*) * (ft_tablen(source) + 1));
	if (new_tab == NULL)
		return (NULL);
	tmp = new_tab;
	while (*source != NULL)
	{
		*tmp = ft_strdup(*source);
		tmp++;
		source++;
	}
	*tmp = NULL;
	return (new_tab);
}
