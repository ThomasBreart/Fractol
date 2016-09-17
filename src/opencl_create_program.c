/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opencl_create_program.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbreart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 01:59:19 by tbreart           #+#    #+#             */
/*   Updated: 2016/09/17 03:27:40 by tbreart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char		*load_kernel_source(const char *filename)
{
	char			*source_str;
	struct stat		stats;
	int				fd;

	if (lstat(filename, &stats) == -1)
	{
		ft_putendl_fd("Error: kernel source not found", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!(fd = open(filename, O_RDONLY)))
	{
		ft_putendl_fd("Error: failed to load kernel source\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	source_str = (char*)malloc(stats.st_size);
	read(fd, source_str, stats.st_size);
	close(fd);
	return (source_str);
}

void			create_program(t_opencl *opencl)
{
	char		*filename;
	char		*source_str;

	filename = ft_strdup("./src/fractals.cl");
	source_str = load_kernel_source(filename);
	opencl->program = clCreateProgramWithSource(opencl->context, 1, (const char**)&source_str, NULL, &opencl->ret);
	if (!opencl->program)
	{
		ft_putendl_fd("Error: failed to create the compute program", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (clBuildProgram(opencl->program, 1, &opencl->device_id, NULL, NULL, NULL) != CL_SUCCESS)
	{
		ft_putendl_fd("Error: failed to build the program executable", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	free(source_str);
	free(filename);
}
