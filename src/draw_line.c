
#include "fractol.h"

void	img_pixel_put(t_env *e, int x, int y, t_var *var)
{
	unsigned int	int_color;


	if (var->iterations == var->iteration_max)
		int_color = mlx_get_color_value(e->mlx, 0x000000);
	else
	{
		//int_color = mlx_get_color_value(e->mlx, 0xFF0000);
		//int_color = int_color * var->iterations / var->iteration_max;
		int_color = 10 * var->iterations;
	}
	memcpy(e->data + (y * e->sizeline) + ((e->bpp / 8) * x), &int_color, 3);
}
