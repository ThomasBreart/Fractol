/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_strsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 17:28:08 by tbreart           #+#    #+#             */
/*   Updated: 2016/06/19 17:29:08 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_word(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			++j;
		++i;
	}
	return (j);
}

static char		*ft_cpy_word(char const *s, char c, const char *filename)
{
	int		a;
	char	*tmp;

	a = 0;
	if (!s)
		return (NULL);
	while (s[a] != c && s[a] != '\0')
		++a;
	tmp = s_strsub(s, 0, a, filename);
	return (tmp);
}

char			**s_strsplit(char const *s, char c, const char *filename)
{
	int		i;
	int		j;
	char	**str;
	int		t;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	t = ft_get_word(s, c);
	str = (char**)s_memalloc(sizeof(char*) * t + sizeof(char*), filename);
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			str[j++] = ft_cpy_word(&s[i], c, filename);
		++i;
	}
	str[j] = NULL;
	return (str);
}
