/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:08:30 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/10 13:46:13 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_map *fdf_parsing(t_fdf_map *map, char **tab, t_vars *vars)
{
	char 	*str;
	int		fd;
	
	fd = open(tab[0], O_RDONLY);
	str = gwf(fd);
	close(fd);
	if (!str)
		fdf_error(vars, "Error in fdf_parsing function\n");
	map->info = fdf_summary_parsing(str);
	if (map->info.length == 0 || map->info.width == 0)
		free (str);
	if (map->info.length == 0 || map->info.width == 0)
		fdf_error(vars, "Error No Width or No Length\n");
	map->vertices = ft_calloc((map->info.width * map->info.length), sizeof(t_fdf_vertex));
	if (!map->vertices)
		free (str);
	if (!map->vertices)
		fdf_error(vars, "Error in fdf_mapping function\n");
	map = fdf_vertices(map, str);
	free (str);
	return (map);
}
