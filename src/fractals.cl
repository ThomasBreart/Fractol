
typedef	struct s_var
{
	double	plan_x1;
	double	plan_x2;
	double	plan_y1;
	double	plan_y2;
	double	zoom_x;
	double	zoom_y;
	int		win_abs;
	int		win_ord;
	int		iteration_max;
	int		iterations;
	int	(*fractal_func[8])(double, double, struct s_var *);
	int		fractal_index;//
	double	julia_x;
	double	julia_y;
	double	color_number;
	int		stop_motion_hook;
	double	z_save;
	int		opencl;
}			t_var;

double			absolu_for_double(double x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}

__kernel void	julia_ship_gpu(__global int *out, __global t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;
	double		pixel_x;
	double		pixel_y;
	int			iterations;
	int			idx;

	pixel_x = get_global_id(0) / var->zoom_x + var->plan_x1;
	pixel_y = get_global_id(1) / var->zoom_y + var->plan_y1;
	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	c_x = var->julia_x;
	c_y = var->julia_y;
	iterations = 0;
	z = 0;
	while (iterations < var->iteration_max && z < 4)
	{
		tmp = pixel_x;
		pixel_x = absolu_for_double(pixel_x * pixel_x) -
							absolu_for_double(pixel_y * pixel_y) + c_x;
		pixel_y = absolu_for_double(2 * tmp * pixel_y) + c_y;
		z = pixel_x * pixel_x + pixel_y * pixel_y;
		++iterations;
	}
	out[idx] = iterations;
}
__kernel void	burning_ship_gpu(__global int *out, __global t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;
	double		pixel_x;
	double		pixel_y;
	int			iterations;
	int			idx;

	pixel_x = get_global_id(0) / var->zoom_x + var->plan_x1;
	pixel_y = get_global_id(1) / var->zoom_y + var->plan_y1;
	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	c_x = pixel_x;
	c_y = pixel_y;
	iterations = 0;
	z = 0;
	while (iterations < var->iteration_max && z < 4)
	{
		tmp = pixel_x;
		pixel_x = absolu_for_double(pixel_x * pixel_x) -
								absolu_for_double(pixel_y * pixel_y) + c_x;
		pixel_y = absolu_for_double(2 * tmp * pixel_y) + c_y;
		z = pixel_x * pixel_x + pixel_y * pixel_y;
		++iterations;
	}
	out[idx] = iterations;
}

__kernel void	julia_gpu(__global int *out, __global t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;
	double		pixel_x;
	double		pixel_y;
	int			iterations;
	int			idx;

	pixel_x = get_global_id(0) / var->zoom_x + var->plan_x1;
	pixel_y = get_global_id(1) / var->zoom_y + var->plan_y1;
	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	c_x = var->julia_x;
	c_y = var->julia_y;
	iterations = 0;
	z = 0;
	while (iterations < var->iteration_max && z < 4)
	{
		tmp = pixel_x;
		pixel_x = (pixel_x * pixel_x) - (pixel_y * pixel_y) + c_x;
		pixel_y = 2 * tmp * pixel_y + c_y;
		z = (pixel_x * pixel_x) + (pixel_y * pixel_y);
		++iterations;
	}
	out[idx] = iterations;
}

__kernel void	mandelbrot_gpu(__global int *out, __global t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;
	double		pixel_x;
	double		pixel_y;
	int			iterations;
	int			idx;

	pixel_x = get_global_id(0) / var->zoom_x + var->plan_x1;
	pixel_y = get_global_id(1) / var->zoom_y + var->plan_y1;
	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	c_x = pixel_x + var->julia_x;//
	c_y = pixel_y + var->julia_y;//
	iterations = 0;
	z = 0;
	while (iterations < var->iteration_max && z < 4)
	{
		tmp = pixel_x;
		pixel_x = (pixel_x * pixel_x) - (pixel_y * pixel_y) + c_x;
		pixel_y = 2 * tmp * pixel_y + c_y;
		z = (pixel_x * pixel_x) + (pixel_y * pixel_y);
		++iterations;
	}
	out[idx] = iterations;
}
