/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 22:09:28 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/18 14:32:43 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

#include <mlx.h>
#include <math.h>
#include "../libft/includes/libft.h"

typedef	struct s_env
{
	int		bpp;
	char	*data;
	void	*mlx;
	void	*win;
}			t_env;

void	display(void);
void	draw2(t_env *e);
#endif
