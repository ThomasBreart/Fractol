/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 22:09:28 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/23 23:08:53 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

#include <stdio.h>
#include <unistd.h>

#include <mlx.h>
#include <math.h>
#include "../libft/includes/libft.h"
# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
//# define KEY_PRESS_MASK (1L<<0)
//# define KEY_PRESS 3

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
	double	plan_x1; //double ?
	double	plan_x2; //double ?
	double	plan_y1;
	double	plan_y2;
	double	zoom_x;
	double	zoom_y;
	int		win_abs;
	int		win_ord;
	int		iteration_max;
	int		iterations;
	int	(*type)(double, double, struct s_var *); // changer_nom ?
	double	julia_x;
	double	julia_y;
}			t_var;

void	display(t_env *e);
void	draw2(t_env *e);
int		expose_hook(t_env *e);
t_var	*get_var(void);
void	img_pixel_put(t_env *e, int x, int y, t_var *var);
int		julia(double pixel_x, double pixel_y, t_var *var);
int		key_hook(int keycode, t_env *e);
int		mandelbrot(double pixel_x, double pixel_y, t_var *var);
int		mouse_hook(int keycode, int x, int y, t_env *e);
void	prepare_draw(t_env *e);
void	set_zoom(t_var *var);
void	zoom_up(const double pixel_x, const double pixel_y);
void	zoom_down(const double pixel_x, const double pixel_y);
#endif
