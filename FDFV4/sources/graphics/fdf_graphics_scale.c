/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics_scale.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:18:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/10 15:34:42 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_graphics_scale(t_vars *vars)
{
	vars->scale.width = FDF_WINDOW_WIDTH - FDF_WINDOW_BORDER * 2;
	vars->scale.heigth = FDF_WINDOW_HEIGHT - FDF_WINDOW_BORDER *2;
	vars->scale.p0.x = FDF_WINDOW_BORDER;
	vars->scale.p0.y = FDF_WINDOW_BORDER;
	vars->scale.pc.x = FDF_WINDOW_WIDTH / 2;
	vars->scale.pc.y = FDF_WINDOW_HEIGHT / 2;
	vars->scale.xone = vars->scale.width / vars->map->info.width;
	vars->scale.yone = vars->scale.heigth / vars->map->info.length;
}