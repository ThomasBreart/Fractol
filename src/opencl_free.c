/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 02:01:46 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 02:01:55 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_opencl(void)
{
	t_opencl	*opencl;
	int			i;

	opencl = get_opencl();
	i = 0;
	while (i < 8)
	{
		opencl->ret = clReleaseKernel(opencl->kernel[i]);
		++i;
	}
	opencl->ret = clReleaseProgram(opencl->program);
	opencl->ret = clReleaseMemObject(opencl->memobj);
	opencl->ret = clReleaseMemObject(opencl->memobj2);
	opencl->ret = clReleaseCommandQueue(opencl->command_queue);
	opencl->ret = clReleaseContext(opencl->context);
	free(opencl->buffer_host);
}
