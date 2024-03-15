/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:37:19 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 15:45:25 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_graphics_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_loop_end(vars);
	return ;
}
