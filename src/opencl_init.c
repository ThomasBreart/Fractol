/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 02:02:48 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 02:04:26 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_struct(t_opencl *opencl, t_var *var)
{
	opencl->platform_id = NULL;
	opencl->device_id = NULL;
	opencl->context = NULL;
	opencl->command_queue = NULL;
	opencl->memobj = NULL;
	opencl->memobj2 = NULL;
	opencl->program = NULL;
	opencl->kernel[0] = NULL;
	opencl->kernel[1] = NULL;
	opencl->kernel[2] = NULL;
	opencl->kernel[3] = NULL;
	opencl->kernel[4] = NULL;
	opencl->kernel[5] = NULL;
	opencl->kernel[6] = NULL;
	opencl->kernel[7] = NULL;
	opencl->image[0] = var->win_abs;
	opencl->image[1] = var->win_ord;
}

void	create_kernel(cl_program program, cl_kernel *kernel, const char *function_name)
{
	cl_int	ret;

	*kernel = clCreateKernel(program, function_name, &ret);
	if (!*kernel || ret != CL_SUCCESS)
	{
		ft_putendl_fd("Error: failed to create kernel", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	init_opencl(t_var *var)
{
	t_opencl	*opencl;
	int			i;

	opencl = get_opencl();
	init_struct(opencl, var);
	if (clGetPlatformIDs(1, &opencl->platform_id, &opencl->ret_num_platforms) != CL_SUCCESS)
	{
		ft_putendl_fd("Error: failed to get the platform", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}

	if (clGetDeviceIDs(opencl->platform_id, CL_DEVICE_TYPE_GPU, 1, &opencl->device_id, &opencl->ret_num_devices) != CL_SUCCESS)
	{
		ft_putendl_fd("Error: failed to create a device group", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}

	opencl->context = clCreateContext(NULL, 1, &opencl->device_id, NULL, NULL, &opencl->ret);
	if (!opencl->context)
	{
		ft_putendl_fd("Error: failed to create a compute context", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}

	opencl->command_queue = clCreateCommandQueue(opencl->context, opencl->device_id, 0, &opencl->ret);
	if (!opencl->command_queue)
	{
		ft_putendl_fd("Error: failed to create the command queue", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	opencl->image_size = var->win_abs * var->win_ord;
	opencl->buffer_host = (int*)malloc(opencl->image_size * sizeof(int));
	opencl->memobj = clCreateBuffer(opencl->context, CL_MEM_WRITE_ONLY, opencl->image_size * sizeof(int), NULL, &opencl->ret);

	opencl->memobj2 = clCreateBuffer(opencl->context, CL_MEM_READ_ONLY, sizeof(t_var), NULL, &opencl->ret);
	if (!opencl->memobj || !opencl->memobj2)
	{
		ft_putendl_fd("Error: failed to allocate device memory", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	create_program(opencl);

	create_kernel(opencl->program, &opencl->kernel[0], "mandelbrot_gpu");
	create_kernel(opencl->program, &opencl->kernel[1], "julia_gpu");
	create_kernel(opencl->program, &opencl->kernel[2], "burning_ship_gpu");
	create_kernel(opencl->program, &opencl->kernel[3], "julia_ship_gpu");
	create_kernel(opencl->program, &opencl->kernel[4], "multibrot_gpu");
	create_kernel(opencl->program, &opencl->kernel[5], "manowar_gpu");
	create_kernel(opencl->program, &opencl->kernel[6], "barnsleyj_gpu");
	create_kernel(opencl->program, &opencl->kernel[7], "spider_gpu");

	i = 0;
	while (i < 8)
	{
		opencl->ret |= clSetKernelArg(opencl->kernel[i], 0, sizeof(cl_mem), (void*)&opencl->memobj);
		opencl->ret |= clSetKernelArg(opencl->kernel[i], 1, sizeof(var), &opencl->memobj2);
		++i;
	}
	if (opencl->ret != CL_SUCCESS)
	{
		ft_putendl_fd("Error: failed to set kernel arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
