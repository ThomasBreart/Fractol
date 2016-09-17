/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 02:03:06 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 03:32:39 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_gpu(t_env *e)
{
	t_var		*var;
	t_opencl	*opencl;
	size_t		i;

	var = get_var();
	opencl = get_opencl();
	clEnqueueWriteBuffer(opencl->command_queue, opencl->memobj2, CL_TRUE, 0,
											sizeof(t_var), var, 0, NULL, NULL);
	opencl->ret = clEnqueueNDRangeKernel(opencl->command_queue,
				opencl->kernel[var->fractal_index], 2, NULL, opencl->image,
														NULL, 0, NULL, NULL);
	opencl->ret = clEnqueueReadBuffer(opencl->command_queue, opencl->memobj,
			CL_TRUE, 0, opencl->image_size * sizeof(int), opencl->buffer_host,
																0, NULL, NULL);
	i = 0;
	while (i < opencl->image_size)
	{
		var->iterations = opencl->buffer_host[i];
		img_pixel_put(e, i % var->win_abs, i / var->win_abs, var);
		++i;
	}
}
