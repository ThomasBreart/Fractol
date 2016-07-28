/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 09:45:17 by tbreart           #+#    #+#             */
/*   Updated: 2015/11/27 06:32:21 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cut_buf(char **buf, size_t j, int ok)
{
	char	*send;
	char	*save;
	size_t	i;

	save = NULL;
	send = ft_strnew(j);
	i = -1;
	while (++i < j)
		send[i] = (*buf)[i];
	if (ok != 2)
	{
		i = ft_strlen((*buf)) - (j + 1);
		save = ft_strnew(i);
		i = 0;
		j++;
		while (j < ft_strlen((*buf)))
		{
			save[i] = (*buf)[j];
			j++;
			i++;
		}
	}
	free((*buf));
	(*buf) = save;
	return (send);
}

int		read_txt(char **buf, int fd, int a)
{
	int		i;
	char	*buf2;
	char	*new;

	if ((*buf) == NULL)
	{
		(*buf) = ft_strnew(BUFF_SIZE);
		i = read(fd, (*buf), BUFF_SIZE);
	}
	else
	{
		buf2 = ft_strnew(BUFF_SIZE);
		i = read(fd, buf2, BUFF_SIZE);
		new = ft_strnew((a * BUFF_SIZE) + BUFF_SIZE);
		ft_strcat(new, (*buf));
		ft_strcat(new, buf2);
		free((*buf));
		free(buf2);
		(*buf) = new;
	}
	return (i);
}

int		check_buf(char **buf, size_t *j, int read_end)
{
	int		i;
	size_t	x;

	i = 2;
	x = 0;
	while ((*buf)[x] != '\0')
	{
		if ((*buf)[x] == '\n')
		{
			i = 1;
			break ;
		}
		x++;
	}
	*j = x;
	if (ft_strlen((*buf)) == x && read_end == 0)
		i = 0;
	return (i);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf;
	t_var		x;

	x.read_end = 1;
	if ((x.a = 1) && (fd < 0 || !line))
		return (-1);
	if ((x.ok = 2) && buf == NULL)
		x.read_end = read_txt(&buf, fd, 42);
	if (x.read_end == -1)
		return (-1);
	while (x.ok == 2)
	{
		x.ok = check_buf(&buf, &x.j, x.read_end);
		if (x.ok == 2 && x.read_end > 0)
			x.read_end = read_txt(&buf, fd, x.a);
		if (x.read_end == -1)
			return (-1);
		if (x.ok != 2)
		{
			(*line) = cut_buf(&buf, x.j, x.ok);
			return (x.ok);
		}
		x.a++;
	}
	return (-1);
}
