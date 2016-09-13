/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gpu2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:40:07 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/13 19:00:20 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MAX_SOURCE_SIZE 10000

void	init_opencl(t_var *var)
{
	t_opencl	*opencl;
	FILE				*fp;
	char				fileName[] = "./src/julia.cl";
	char				*source_str;
	size_t				source_size;

	opencl = get_opencl();
	opencl->platform_id = NULL;
	opencl->device_id = NULL;
	opencl->context = NULL;
	opencl->command_queue = NULL; // init toute les var de la structure ?
	opencl->memobj = NULL;
	opencl->memobj2 = NULL;
	opencl->program = NULL;
	opencl->kernel = NULL;

	opencl->ret = clGetPlatformIDs(1, &opencl->platform_id, &opencl->ret_num_platforms);

	opencl->ret = clGetDeviceIDs(opencl->platform_id, CL_DEVICE_TYPE_GPU, 1, &opencl->device_id, &opencl->ret_num_devices);

	opencl->context = clCreateContext(NULL, 1, &opencl->device_id, NULL, NULL, &opencl->ret);

	opencl->command_queue = clCreateCommandQueue(opencl->context, opencl->device_id, 0, &opencl->ret);

	opencl->image_size = var->win_abs * var->win_ord;
	opencl->buffer_host = (int*)malloc(opencl->image_size * sizeof(int));///
	opencl->memobj = clCreateBuffer(opencl->context, CL_MEM_WRITE_ONLY, opencl->image_size * sizeof(int), NULL, &opencl->ret);

	opencl->memobj2 = clCreateBuffer(opencl->context, 0, sizeof(t_var), NULL, &opencl->ret);///changer le 0
	fp = fopen(fileName, "r");
	if (!fp)
	{
		fprintf(stderr, "failed to load kernel.\n");
		exit(EXIT_FAILURE);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE); // a remplacer avec stat.size
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);

	opencl->program = clCreateProgramWithSource(opencl->context, 1, (const char**)&source_str, (const size_t*)&source_size, &opencl->ret);

	opencl->ret = clBuildProgram(opencl->program, 1, &opencl->device_id, NULL, NULL, NULL);

	opencl->kernel = clCreateKernel(opencl->program, "julia_gpu", &opencl->ret);

	opencl->ret = clSetKernelArg(opencl->kernel, 0, sizeof(cl_mem), (void*)&opencl->memobj);
	opencl->ret = clSetKernelArg(opencl->kernel, 1, sizeof(var), &opencl->memobj2);
	opencl->image[0] = var->win_abs;
	opencl->image[1] = var->win_ord;
	free(source_str);
}

void	free_opencl(void)
{
	t_opencl	*opencl;

	opencl = get_opencl();
	opencl->ret = clReleaseKernel(opencl->kernel);
	opencl->ret = clReleaseProgram(opencl->program);
	opencl->ret = clReleaseMemObject(opencl->memobj);
	opencl->ret = clReleaseMemObject(opencl->memobj2);
	opencl->ret = clReleaseCommandQueue(opencl->command_queue);
	opencl->ret = clReleaseContext(opencl->context);
	free(opencl->buffer_host);
}

void	draw_gpu2(t_env *e)
{
	t_var		*var;
	t_opencl	*opencl;
	size_t		i;

//	char				string[MEM_SIZE];
	var = get_var();
	opencl = get_opencl();

	clEnqueueWriteBuffer(opencl->command_queue, opencl->memobj2, CL_TRUE, 0, sizeof(t_var), var, 0, NULL, NULL);///
	opencl->ret = clEnqueueNDRangeKernel(opencl->command_queue, opencl->kernel, 2, NULL, opencl->image, NULL, 0, NULL, NULL);//pas sur de celle ci

	opencl->ret = clEnqueueReadBuffer(opencl->command_queue, opencl->memobj, CL_TRUE, 0, opencl->image_size * sizeof(int), opencl->buffer_host, 0, NULL, NULL);///pas sursur

	i = 0;
	while (i < opencl->image_size)
	{
		var->iterations = opencl->buffer_host[i];
		img_pixel_put(e, i % var->win_abs, i / var->win_abs, var);
		++i;
	}
}
