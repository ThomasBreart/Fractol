
#include "fractol.h"

void	img_pixel_put(t_env *e, int x, int y, int i)
{
	unsigned int	int_color;

	if (i == 1)
		int_color = mlx_get_color_value(e->mlx, 0x000000);
	else
		int_color = mlx_get_color_value(e->mlx, 0xFF0000);
	memcpy(e->data + (y * e->sizeline) + ((e->bpp / 8) * x), &int_color, 3);
}
