/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:52:03 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 21:26:35 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

 void fdf_parsing(t_main *main, char *filename)
{
	char	*str;
	int		fd;
	char	*arg;

	arg = ft_strremovec(filename, ' ');
	if (!arg)
		fdf_error(main, "Error in ft_strremovec : Malloc\n");
	free (filename);
	main->arg = arg;
	fd = open(main->arg, O_RDONLY);
	if (fd == -1)
	{
		close (fd);
		fdf_error(main, "Error in FDF_PARSING function : Could not open file\n");
	}
	str = gwf(fd);
	close (fd);
	if (!str)
		fdf_error(main, "Error in GWF function : Malloc unitialized\n");
	main->map->info = fdf_map_info(str);
	if (main->map->info.width == -1 || main->map->info.width == 0 || main->map->info.height == 0)
		fdf_error(main, "error in fdf_parsing function : incorrect map\n");
	main->map->vertices = ft_calloc((main->map->info.width * main->map->info.height), sizeof(t_map_vertex));
	if (!main->map->vertices)
		fdf_error(main, "Error in GWF function : Malloc unitialized\n");
	main->map->vertices = fdf_vertices(main, str);
	free (str);
}
