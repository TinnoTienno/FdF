/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:45:25 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:21:34 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vertex	fdf_vertex(int x, int y, char *str, int *index)
{
	t_vertex	new;

	new.val[0][0] = x;
	new.val[0][1] = y;
	new.val[0][2] = 0;
	new.val[0][2] = ft_atolle(str, index);
	new.val[1][2] = new.val[0][2];
	new.color[0] = 0xFFFFFF;
	if (str[*index] == ',')
	{
		*index = *index + 3;
		new.color[0] = ft_atoi_base(str, "0123456789ABCDEF", index);
	}
	return (new);
}

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
	while (str[i] && (ft_isalnum(str[i]) || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F')))
		i++;
	if (!str[i] || str[i] == '\n' || str[i] == ' ')
		return (0);
	else
		return (3);
}

static void	fdf_zmin_zmax_edit(t_main *main, int y, int x)
{
	if (main->minfo.zmin[0] > (int) main->vertices[y][x].val[0][2])
		main->minfo.zmin[0] = (int) main->vertices[y][x].val[0][2];
	if (main->minfo.zmax[0] < (int) main->vertices[y][x].val[0][2])
		main->minfo.zmax[0] = (int) main->vertices[y][x].val[0][2];
}

static void	fdf_map_lines(t_main *main, int y, t_parsing *parsing)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (parsing->line[i] && parsing->line[i] == ' ')
		i++;
	while (x < main->minfo.width && parsing->line[i])
	{
		if (fdf_vertex_error(&parsing->line[i]))
			fdf_error(main, "Error in fdf_map_lines function : Incorrect map\n");
		main->vertices[y][x] = fdf_vertex(x, y, parsing->line, &i);
		fdf_zmin_zmax_edit(main, y, x);
		x++;
		while (parsing->line[i] && parsing->line[i] == ' ')
			i++;
	}
	if (x < main->minfo.width)
		fdf_error(main, "Error in fdf_map_lines function : Incorrect map\n");
	if (parsing->line[i])
		fdf_error(main, "Error in fdf_map_lines function : Incorrect map\n");
}

void	fdf_vertices(t_main *main)
{
	int			y;
	t_parsing	*tmp;

	y = 0;
	tmp = main->parsing;
	while (y < main->minfo.height)
	{
		main->vertices[y] = ft_calloc(main->minfo.width, sizeof(t_vertex));
		if (!main->vertices[y])
			fdf_error(main, "Error in fdf_vertices function : Malloc\n");
		fdf_map_lines(main, y, tmp);
		tmp = tmp->next;
		y++;
	}
}
