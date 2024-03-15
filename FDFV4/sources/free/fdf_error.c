/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:54:47 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/07 17:29:00 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void	fdf_free_map(t_fdf_map *map)
{	
	free (map->vertices);
	free (map);
}

static void	fdf_free_vars(t_vars *vars)
{
	if (!vars->mlx && !vars->win && !vars->img.img)
		return (free(vars));
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free (vars);
	// if (vars->win)
		
}
void	fdf_error(t_vars *vars, char *print)
{
	printf("%p\n", vars->map->vertices);
	fd_printf(2, "%s", print);
	if (vars)
	{
		if (vars->map)
			fdf_free_map(vars->map);
		fdf_free_vars(vars);
	}
	exit(EXIT_FAILURE);
}