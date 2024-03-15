/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:17:02 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 18:10:59 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf_mapping	fdf_mapping_elem(char *str, int *i, int x, int y)
{
	t_fdf_mapping	mappingelem;


	mappingelem.z = ft_atoi(&str[*i]);
	mappingelem.x = x;
	mappingelem.y = y;
	while (str[*i] && ft_isdigit(str[*i]))
		*i += 1;
	if (str[*i] && str[*i] != ',')
	{
		*i += 3;
		mappingelem.colors = ft_atoi_base(&str[*i], 16);
		while (str[*i] && ft_isalnum(str[*i]))
			*i += 1;
	}
	else
		mappingelem.colors = 0;
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\n'))
		*i += 1;
	return (mappingelem);
}

t_fdf_mapping	**fdf_mapping_line(char *str, t_fdf_info_summary *summary, int *i, int y)
{
	t_fdf_mapping 		*mappingline;
	t_fdf_info_summary	*summary;
	int					x;

	x = 0;
	summary = fdf_summary_init_free(0);
	mappingline = malloc (sizeof(t_fdf_mapping *) * summary->length);
	if (!mappingline)
		return (NULL);
	if (x == 0)
	{
		mappingline[x] = fdf_mapping_elem(str, i, x, y);
		summary->zmax = mappingline[x].z;
		summary->zmin = mappingline[x].z;
		x++;
	}
	while (x < summary->length)
	{
		mappingline[x] = fdf_mapping_elem(str, i, x, y);
		if (mappingline[x].z > summary->zmax)
			summary->zmax = mappingline[x].z;
		else if (mappingline[x].z < summary->zmin)
			summary->zmin = mappingline[x].z;
		x++;
	}
	return (mappingline);
}