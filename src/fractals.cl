
typedef struct s_comp
{
	double		r;
	double		i;
}				t_comp;

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

t_comp		ft_addcomp(t_comp z1, t_comp z2)
{
	z1.r += z2.r;
	z1.i += z2.i;
	return (z1);
}

t_comp		ft_mulcomp(t_comp z1, t_comp z2)
{
	t_comp	tmp;

	tmp.r = z1.r * z2.r - z1.i * z2.i;
	tmp.i = z2.r * z1.i + z1.r * z2.i;
	return (tmp);
}

t_comp		ft_mulcompreal(t_comp z1, double k)
{
	z1.r *= k;
	z1.i *= k;
	return (z1);
}

t_comp		ft_subcomp(t_comp z1, t_comp z2)
{
	z1.r -= z2.r;
	z1.i -= z2.i;
	return (z1);
}

t_comp		ft_initcomp(double r, double i)
{
	t_comp	tmp;

	tmp.r = r;
	tmp.i = i;
	return (tmp);
}

double			absolu_for_double(double x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}

__kernel void	spider_gpu(__global int *out, __global t_var *var)
{
	t_comp		z;
	t_comp		c;
	int			iterations;
	int			idx;

	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	z = ft_initcomp(get_global_id(0) / var->zoom_x + var->plan_x1,
					get_global_id(1) / var->zoom_y + var->plan_y1);
	c = z;
	iterations = 0;
	while (iterations < var->iteration_max)
	{
		z = ft_addcomp(ft_mulcomp(z, z), c);
		c.r /= 2;
		c.i /= 2;
		c = ft_addcomp(c, z);
		if (z.r * z.r + z.i * z.i > 4)
			break ;
		++iterations;
	}
	out[idx] = iterations;
}

__kernel void	barnsleyj_gpu(__global int *out, __global t_var *var)
{
	t_comp	z;
	t_comp	c;
	int			iterations;
	int			idx;

	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	c = ft_initcomp(var->julia_x, var->julia_y);
	z = ft_initcomp(get_global_id(0) / var->zoom_x + var->plan_x1,
					get_global_id(1) / var->zoom_y + var->plan_y1);
	iterations = 0;
	while (iterations < var->iteration_max)
	{
		if (z.r > 0)
		{
			z.r -= 1;
			z = ft_mulcomp(z, c);
		}
		else
		{
			z.r += 1;
			z = ft_mulcomp(z, c);
		}
		if ((z.r * z.r + z.i * z.i) > 4)
			break ;
		++iterations;
	}
	out[idx] = iterations;

}

__kernel void	manowar_gpu(__global int *out, __global t_var *var)
{
	t_comp		z;
	t_comp		c;
	t_comp		m;
	t_comp		tmp;
	int			iterations;
	int			idx;

	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	c = ft_initcomp(get_global_id(0) / var->zoom_x + var->plan_x1,
			get_global_id(1) / var->zoom_y + var->plan_y1);
	z = ft_initcomp(0, 0);
	m = z;
	iterations = 0;
	while (iterations < var->iteration_max)
	{
		tmp = z;
		z = ft_addcomp(ft_addcomp(ft_mulcomp(z, z), m), c);
		if (z.r * z.r + z.i * z.i > 4)
			break ;
		m = tmp;
		++iterations;
	}
	out[idx] = iterations;
}

__kernel void	multibrot_gpu(__global int *out, __global t_var *var)
{
	t_comp		z;
	t_comp		c;
	int			iterations;
	int			idx;

	idx = get_global_size(0) * get_global_id(1) + get_global_id(0);
	z = ft_initcomp(get_global_id(0) / var->zoom_x + var->plan_x1,
					get_global_id(1) / var->zoom_y + var->plan_y1);
	c = z;
	iterations = 0;
	while (iterations < var->iteration_max)
	{
		z = ft_addcomp(ft_mulcomp(ft_mulcomp(ft_mulcomp(z, z), z), z), c);
		if (z.r * z.r + z.i * z.i > 4)
			break ;
		++iterations;
	}
	out[idx] = iterations;
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
