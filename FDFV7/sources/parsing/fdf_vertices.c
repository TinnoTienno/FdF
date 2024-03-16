/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:04:52 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 23:41:27 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_vertex_error(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = ft_atolle(str, &i);
	if (nb > 2147483647 || nb < -2147483648)
	{
		printf("1\n");
		return (1);
	}
	if (!str[i])
		return (0);
	if (str[i] != ',')
	{
		printf("2\n");
		return (2);
	}
	i++;
	while (str[i] && (ft_isalnum(str[i]) || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'f')))
		i++;
	if (str[i] != 0 && str[i] != 10 && str[i] != '\n')
	{
		printf("3\n");
		return (3);
	}
	return (0);
}

static t_vertex fdf_vertex(int x, int y, char *str)
{
	t_vertex	new;
	int i;
	
	new.x = x;
	new.y = y;
	i = 0;
	new.z = 0;
	new.z = ft_atolle(str, &i);
	new.color = 0xFFFFFF;
	if (str[i])
		new.color = ft_atoi_base(&str[i + 3], "0123456789ABCDEF");
	return (new);
}
static void	fdf_zmin_zmax_edit(t_main *main, int y, int x)
{
	if (main->map.info.zmin > (int) main->map.vertices[y][x].z)
		main->map.info.zmin = (int) main->map.vertices[y][x].z;
	if (main->map.info.zmax < (int) main->map.vertices[y][x].z)
		main->map.info.zmax = (int) main->map.vertices[y][x].z;
}
static void	fdf_map_lines(t_main *main, int y, t_parsing *line)
{
	int	x;
	char **linetab;

	x = 0;
	linetab = ft_split(line->line, ' ');
	if (!linetab)
		fdf_error(main, "Error in function fdf_map_lines : Malloc\n");
	while (x < main->map.info.width)
	{
		if (fdf_vertex_error(linetab[x]))
		{
			ft_freectab(linetab);
			fdf_error(main, "Error in fdf_vertex : Incorrect map 1\n");
		}
		main->map.vertices[y][x] = fdf_vertex(x, y, linetab[x]);
		fdf_zmin_zmax_edit(main, y, x);
		x++;
	}
	if (linetab[x])
	{
		ft_freectab(linetab);
		fdf_error(main, "Error in fdf_vertex : Incorrect map\n");
	}	
	ft_freectab(linetab);
}
void	fdf_vertices(t_main *main)
{
	int			y;
	t_parsing	*tmp;

	y = 0;
	tmp = main->list;
	while (y < main->map.info.height)
	{
		main->map.vertices[y] = ft_calloc(sizeof(t_vertex), main->map.info.width);
		if (!main->map.vertices[y])
			fdf_error(main, "Error in fdf_vertices function : Malloc unitialized\n");
		fdf_map_lines(main, y, tmp);
		// fdf_display_vertex(main, y, 0);
		tmp = tmp->next;
		y++;		
	}
}