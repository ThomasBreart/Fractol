/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 22:09:28 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/19 04:58:24 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <unistd.h>
# include <Opencl/opencl.h>
# include <sys/stat.h>
# include <mlx.h>
# include "../libft/includes/libft.h"

# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6

# define KEY_SPACE 49
# define KEY_ESC 53
# define KEY_SUM_NUMPAD 69
# define KEY_SUB_NUMPAD 78
# define KEY_1_NUMPAD 83
# define KEY_2_NUMPAD 84
# define KEY_4_NUMPAD 86
# define KEY_5_NUMPAD 87
# define KEY_7_NUMPAD 89
# define KEY_8_NUMPAD 91
# define KEY_PAGE_DOWN 121
# define KEY_PAGE_UP 116
# define KEY_F16 106
# define MOUSE_LEFT_CLICK 1
# define MOUSE_RIGHT_CLICK 2
# define MOUSE_WHEEL_UP 5
# define MOUSE_WHEEL_DOWN 4

typedef	struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img_ptr;
	int					bpp;
	char				*data;
	int					sizeline;
}						t_env;

typedef	struct			s_var
{
	double				plan_x1;
	double				plan_x2;
	double				plan_y1;
	double				plan_y2;
	double				zoom_x;
	double				zoom_y;
	int					win_abs;
	int					win_ord;
	int					iteration_max;
	int					iterations;
	int					(*fractal_func[8])(double, double, struct s_var *);
	int					fractal_index;
	double				julia_x;
	double				julia_y;
	double				color_number;
	int					stop_motion_hook;
	double				z_save;
	int					opencl;
	int					hud;
}						t_var;

typedef	struct			s_opencl
{
	cl_int				ret;
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_device_id		device_id;
	cl_uint				ret_num_devices;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_mem				memobj;
	cl_mem				memobj2;
	cl_program			program;
	cl_kernel			kernel[8];
	size_t				image_size;
	int					*buffer_host;
	size_t				image[2];
}						t_opencl;

double					absolu_for_double(double number);
int						barnsleyj(double pixel_x, double pixel_y, t_var *var);
int						burning_ship(double pixel_x, double pixel_y,
																	t_var *var);
void					change_fractal_up(void);
void					change_fractal_down(void);
void					color_number_down_10(void);
void					color_number_down_100(void);
void					color_number_down_1000(void);
void					color_number_up_10(void);
void					color_number_up_100(void);
void					color_number_up_1000(void);
void					create_program(t_opencl *opencl);
void					display(t_env *e);
void					draw_gpu(t_env *e);
int						expose_hook(t_env *e);
void					free_opencl(void);
double					ft_carre(double x);
t_opencl				*get_opencl(void);
t_var					*get_var(void);
void					img_pixel_put(t_env *e, int x, int y, t_var *var);
void					init(t_env *e, t_options *options);
void					init_opencl(t_var *var);
void					init_plan(t_var *var);
void					iteration_max_up(void);
void					iteration_max_down(void);
int						julia(double pixel_x, double pixel_y, t_var *var);
int						julia_ship(double pixel_x, double pixel_y, t_var *var);
int						key_hook(int keycode, t_env *e);
int						mandelbrot(double pixel_x, double pixel_y, t_var *var);
int						manowar(double pixel_x, double pixel_y, t_var *var);
int						multibrot(double pixel_x, double pixel_y, t_var *var);
int						motion_hook(int x, int y, t_env *e);
void					mouse_zoom_down(const double pixel_x,
														const double pixel_y);
void					mouse_zoom_up(const double pixel_x,
														const double pixel_y);
int						mouse_hook(int keycode, int x, int y, t_env *e);
void					set_zoom(t_var *var);
void					show_hud(t_env *e);
int						spider(double pixel_x, double pixel_y, t_var *var);
void					stop_motion_hook(void);

#endif
