/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:54:47 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/06 14:12:19 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void	fdf_free_map(t_fdf_map *map)
{	
	if (!map->vertices)
		return (free(map));
	free (map->vertices);
	free (map);
}

static void	fdf_free_vars(t_vars *vars)
{
	if (!vars->mlx || !vars->win)
		return (free(vars));
}
void	fdf_error(t_fdf_map *map, t_vars *vars, char *print)
{
	fd_printf(2, "%s", print);
	if (map)
		fdf_free_map(map);
	if (vars)
		fdf_free_vars(vars);
	exit(EXIT_FAILURE);
}