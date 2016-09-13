
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


__kernel void julia_gpu(__global int *out, __global t_var *var)
{
	double		z;
	double		c_x;
	double		c_y;
	double		tmp;
	double		pixel_x;
	double		pixel_y;
	size_t			x_dim;
	size_t			y_dim;
	size_t		width;
	int			y;

	x_dim = get_global_id(0);
	y_dim = get_global_id(1);
	pixel_x = x_dim / var->zoom_x + var->plan_x1;
	pixel_y = y_dim / var->zoom_y + var->plan_y1;
	width = get_global_size(0);
	int idx = width * y_dim + x_dim;
	c_x = var->julia_x;
	c_y = var->julia_y;
	y = 0;
	z = 0;
	while (y < var->iteration_max && z < 4)
	{
		tmp = pixel_x;
		pixel_x = (pixel_x * pixel_x) - (pixel_y * pixel_y) + c_x;
		pixel_y = 2 * tmp * pixel_y + c_y;
		z = (pixel_x * pixel_x) + (pixel_y * pixel_y);
		++y;
	}
	if (y == var->iteration_max)
		out[idx] = 0;
	else
		out[idx] = y;
}
