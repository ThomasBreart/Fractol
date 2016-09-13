__kernel void julia_gpu(__global int *out)
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
	size_t		abc;
	int			y;

	x_dim = get_global_id(0);
	y_dim = get_global_id(1);
	pixel_x = x_dim / 166.0 - 3.0;
	pixel_y = y_dim / 250.0 - 2.0;
	width = get_global_size(0);
	abc = get_global_size(1);
	int idx = width * y_dim + x_dim;
	c_x = 0.3;
	c_y = 0.5;
	y = 0;
	z = 0;
	while (y < 100 && z < 4)
	{
		tmp = pixel_x;
		pixel_x = (pixel_x * pixel_x) - (pixel_y * pixel_y) + c_x;
		pixel_y = 2 * tmp * pixel_y + c_y;
		z = (pixel_x * pixel_x) + (pixel_y * pixel_y);
		++y;
	}
	if (y == 100)
	{
		out[idx] = 0;
	}
	else
	{
		out[idx] = y;
	}
}
