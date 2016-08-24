
#include "fractol.h"

void	img_pixel_put(t_env *e, int x, int y, t_var *var)
{
	unsigned int	int_color;


//	if (x == 250 || y == 250)
//		int_color = mlx_get_color_value(e->mlx, 0xFF0000);
	if (var->iterations == var->iteration_max)
		int_color = mlx_get_color_value(e->mlx, 0xFFFFFF);
	else
	{
		//int_color = mlx_get_color_value(e->mlx, 0xFF0000);
		//int_color = int_color * var->iterations / var->iteration_max;
		int_color = var->color_number * var->iterations;
	}
	memcpy(e->data + (y * e->sizeline) + ((e->bpp / 8) * x), &int_color, 3);
}
