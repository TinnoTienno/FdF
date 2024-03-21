/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:04:52 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/21 15:29:02 by eschussl         ###   ########.fr       */
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
		return (1);
	if (!str[i] || str[i] == '\n' || str[i] == ' ')
		return (0);
	if (str[i] != ',')
		return (2);
	i++;
	while (str[i] && (ft_isalnum(str[i]) || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'f')))
		i++;
	if (!str[i] || str[i] == '\n' || str[i] == ' ')
		return (0);
	else
		return (3);
}

static t_vertex fdf_vertex(int x, int y, char *str, int *index)
{
	t_vertex	new;
	
	new.x = x;
	new.y = y;
	new.z = 0;
	new.z = ft_atolle(str, index);
	new.color = 0xFFFFFF;
	if (str[*index] == ',')
	{	
		*index = *index + 3;
		new.color = ft_atoi_base(str, "0123456789ABCDEF", index);
	}
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
	int	i;
	
	x = 0;
	i = 0;
	while (line->line[i] && line->line[i] == ' ')
			i++;
	while (x < main->map.info.width && line->line[i])
	{
		if (fdf_vertex_error(&line->line[i]))
			fdf_error(main, "Error in fdf_map_lines function : Incorrect map\n");
		main->map.vertices[y][x] = fdf_vertex(x, y, line->line, &i);
		fdf_zmin_zmax_edit(main, y, x);
		x++;
		while (line->line[i] && line->line[i] == ' ')
			i++;
	}
	if (x < main->map.info.width)
		fdf_error(main, "Error in fdf_map_lines function : Incorrect map\n");
	if (line->line[i])
		fdf_error(main, "Error in fdf_map_lines function : Incorrect map\n");
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
		tmp = tmp->next;
		y++;		
	}
}