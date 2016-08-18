/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 22:09:28 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/18 17:21:21 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

#include <stdio.h>

#include <mlx.h>
#include <math.h>
#include "../libft/includes/libft.h"

typedef	struct s_env
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	int		bpp;
	char	*data;
	int		sizeline;
}			t_env;

typedef	struct s_var
{
	double	plan_abs; //double ?
	double	plan_ord;
	int		win_abs;
	int		win_ord;
	int		iterations;
}			t_var;

void	display();
void	draw2(t_env *e);
t_var	*get_var(void);
void	prepare_draw(t_env *e);
void	img_pixel_put(t_env *e, int x, int y, int i);
#endif
