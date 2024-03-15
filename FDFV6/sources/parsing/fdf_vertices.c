/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:31:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 21:39:13 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_vertex_error(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = ft_atoil(str, &i);
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	if (!str[i])
		return (0);
	if (str[i] != ',')
		return (2);
	i++;
	while (str[i] && (ft_isalnum(str[i]) || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'f')))
		i++;
	if (str[i] != 0)
		return (3);
	return (0);
}

static t_map_vertex fdf_vertex(int x, int y, char *str)
{
	t_map_vertex	new;
	int				i;

	new.x[1] = 0;
	new.y[1] = 0;
	new.z[1] = 0;
	new.colors[1] = 0;
	new.x[0] = x;
	new.colors[0] = 0xFFFFFF;
	new.y[0] = y;
	i = 0;
	new.z[0] = ft_atoil(str, &i);
	if (str[i])
		new.colors[0] = ft_atoi_base(&str[i + 3], "0123456789ABCDEF");
	return (new);
}

static t_map_info fdf_min_max_edit(t_map *map, int j)
{
	if (map->info.zmin > map->vertices[j].z[0])
		map->info.zmin = map->vertices[j].z[0];
	if (map->info.zmax < map->vertices[j].z[0])
		map->info.zmax = map->vertices[j].z[0];
	return (map->info);
}
static void fdf_vertex_line(t_main *main, char **tab, int y, int *i)
{
	char	**line;
	int		x;
	
	x = 0;
	line = ft_split(tab[y], ' ');
	if (!line)
		ft_freectab(tab);
	if (!line)
		fdf_error(main, "Error in fdf_vertices function : Malloc\n");
	while (main->map->info.width > x)
	{
		if (fdf_vertex_error(line[x]))
		{
			ft_freectab(tab);
			ft_freectab(line);
			fdf_error(main, "Error in fdf_vertex : Incorrect map\n");
		}
		main->map->vertices[*i] = fdf_vertex(x, y, line[x]);
		// printf("x : %f, y : %f, z : %f, color : %d\n", main->map->vertices[*i].x[0], main->map->vertices[*i].y[0], main->map->vertices[*i].z[0], main->map->vertices[*i].colors[0]);
		main->map->info = fdf_min_max_edit(main->map, *i);
		x++;
		*i += 1;
	}
	ft_freectab(line);
}

t_map_vertex *fdf_vertices(t_main *main, char *str)
{
	char	**tab;
	int		y;
	int		i;
	
	// printf("str : \n%s\n", str);
	tab = ft_split(str, '\n');
	if (!tab)
		fdf_error(main, "Error in fdf_vertices function : Malloc\n");
	y = 0;
	i = 0;
	while (tab[y])
	{
		fdf_vertex_line(main, tab, y, &i);
		y++;
	}
	ft_freectab(tab);
	return (main->map->vertices);
}
