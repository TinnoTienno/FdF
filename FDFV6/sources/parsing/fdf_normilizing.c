/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_normilizing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:29:22 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 21:26:58 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void fdf_normilizing(t_main *main)
{
	int i;
	double	widthcenter;
	int	heightcenter;
	
	widthcenter = (main->map->info.width - 1) / 2;
	heightcenter = (main->map->info.height - 1) / 2;
	i = 0;
	while (i < main->map->info.width * main->map->info.height)
	{
		main->map->vertices[i].x[0] = main->map->vertices[i].x[0] - widthcenter;
		main->map->vertices[i].y[0] = main->map->vertices[i].y[0] - heightcenter;
		i++;
	}
}