/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:54:06 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/07 17:09:30 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_error_file(int size, char **tab)
{
	int	i;

	i = 0;
	if (size != 1)
		return (1);
	while (tab[0][i] == ' ' && tab[0][i] )
		i++;
	while (tab[0][i] && tab[0][i] != ' ')
	{
		if (ft_isalnum(tab[0][i] == 0) && tab[0][i] != '.' && tab[0][i] !='/')
			return (1);
		i++;
	}
	if (i < 4)
		return (1);
	if (tab[0][i - 1] != 'f' || tab[0][i - 2] != 'd' || tab[0][i - 3] != 'f' || tab[0][i - 4] != '.')
		return (1);
	return (0);
}
t_fdf_map	*fdf_mapping(int size, char **tab, t_vars *vars)
{
	t_fdf_map *map;

	map = ft_calloc(1, sizeof(t_fdf_map));
	if (!map)
		fdf_error(vars, "Error in fdf_mapping function\n");
	if (fdf_error_file(size, tab) == 1)
		fdf_error(vars, "Error in fdf_error_file function\n");
	map = fdf_parsing(map, tab, vars);
	return (map);
}