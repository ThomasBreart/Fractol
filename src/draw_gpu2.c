/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gpu2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 16:40:07 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/13 14:57:33 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MAX_SOURCE_SIZE 10000

void	draw_gpu2(t_env *e)
{
	t_var				*var;
	size_t					image_size;
	int						*buffer_host;

	cl_int				ret;
	cl_platform_id		platform_id = NULL;
	cl_uint				ret_num_platforms;
	
	cl_device_id		device_id = NULL;
	cl_uint				ret_num_devices;

	cl_context			context = NULL;

	cl_command_queue	command_queue = NULL;

	cl_mem				memobj = NULL;

	FILE				*fp;
	char				fileName[] = "./src/julia.cl";
	char				*source_str;
	size_t				source_size;

	cl_program			program = NULL;

	cl_kernel			kernel = NULL;

//	char				string[MEM_SIZE];

	var = get_var();

	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);

	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);

	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

	image_size = var->win_abs * var->win_ord * sizeof(int);
	buffer_host = (int*)malloc(image_size);///
	memobj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, image_size, NULL, &ret);///

	fp = fopen(fileName, "r");
	if (!fp)
	{
		fprintf(stderr, "failed to load kernel.\n");
		exit(EXIT_FAILURE);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE); // a remplacer avec stat.size
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);

	program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &ret);

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	kernel = clCreateKernel(program, "julia_gpu", &ret);

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&memobj);
	///envoyer aussi d autre vaariables
	printf("OK HERE1\n");

	size_t		total_size = var->win_abs * var->win_ord;
	size_t		size2[2];
	size2[0] = 1000;
	size2[1] = 1000;
	printf("OK HERE2\n");
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, size2, NULL, 0, NULL, NULL);//pas sur de celle ci
	printf("OK HERE3\n");

	ret = clEnqueueReadBuffer(command_queue, memobj, CL_TRUE, 0, image_size, buffer_host, 0, NULL, NULL);///pas sursur

	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(memobj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);
	free(source_str);

	size_t		i = 0;
	printf("OK HERE4\n");
	fp = fopen("rendu", "w");
	while (i < total_size)
	{
		fprintf(fp, "--%d\n", buffer_host[i]);
		var->iterations = buffer_host[i];
		img_pixel_put(e, i % var->win_abs, i / var->win_abs, var);
		++i;
	}

	free(buffer_host);
}
