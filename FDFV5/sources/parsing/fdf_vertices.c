/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:52:38 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/06 14:20:27 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static int	fdf_atoi_pass(char *str)
{
	int i;
	
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '-'))
		i++;
	if (str[i] == ',')
		i++;
	return (i);
}
static t_fdf_vertex fdf_vertex(int x, int y, char *str, int *i)
{
	t_fdf_vertex new;

	new.x = x;
	new.colors = 0;
	new.y = y;
	new.z = ft_atoi(&str[*i]);
	*i += fdf_atoi_pass(&str[*i]);
	new.colors = ft_atoi_base(&str[*i], 16);
	*i += fdf_atoi_pass(&str[*i]);
	return (new);
}

static t_fdf_info fdf_min_max_edit(t_fdf_map *map, int j)
{
	if (map->info.zmin > map->vertices[j].z)
		map->info.zmin = map->vertices[j].z;
	if (map->info.zmax < map->vertices[j].z)
		map->info.zmax = map->vertices[j].z;
	return (map->info);
}
t_fdf_map *fdf_vertices(t_fdf_map *map, char *str)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] && (str[i]== ' ' || str[i] == '\n'))
			i++;
		else
		{
			map->vertices[j] = fdf_vertex(x, y, str, &i);
			map->info = fdf_min_max_edit(map, j);
			j++;
			x++;
			if (x >= map->info.length)
				y++;
			if (x >= map->info.length)
				x = 0;
		}
	}
	return (map);
}
