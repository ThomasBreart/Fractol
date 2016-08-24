/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 22:09:28 by tbreart           #+#    #+#             */
/*   Updated: 2016/08/24 20:23:57 by tbreart          ###   ########.fr       */
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
//#define NoEventMask 0L
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
	int	(*fractal_func[5])(double, double, struct s_var *); // changer_nom ?
	int		fractal_index;//
	double	julia_x;
	double	julia_y;
	double	color_number;
	int		stop_motion_hook;
	double	z_save;
}			t_var;

double	absolu_for_double(double number);
int		burning_ship(double pixel_x, double pixel_y, t_var *var);
void	change_fractal_up(void);
void	change_fractal_down(void);
void	color_number_down_10(void);
void	color_number_down_100(void);
void	color_number_down_1000(void);
void	color_number_up_10(void);
void	color_number_up_100(void);
void	color_number_up_1000(void);
void	display(t_env *e);
int		expose_hook(t_env *e);
double	ft_carre(double x);
t_var	*get_var(void);
void	img_pixel_put(t_env *e, int x, int y, t_var *var);
void	init_plan(t_var *var);
void	iteration_max_up(void);
void	iteration_max_down(void);
int		julia(double pixel_x, double pixel_y, t_var *var);
int		julia_ship(double pixel_x, double pixel_y, t_var *var);
int		plop(double pixel_x, double pixel_y, t_var *var);
int		key_hook(int keycode, t_env *e);
int		mandelbrot(double pixel_x, double pixel_y, t_var *var);
int		motion_hook(int x, int y, t_env *e);
int		mouse_hook(int keycode, int x, int y, t_env *e);
void	set_zoom(t_var *var);
void	stop_motion_hook(void);
void	mouse_zoom_up(const double pixel_x, const double pixel_y);
void	mouse_zoom_down(const double pixel_x, const double pixel_y);
#endif
