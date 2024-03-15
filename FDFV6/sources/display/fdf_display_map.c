/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:45:09 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 22:02:22 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display_map(t_main *main)
{
	int i;
	
	i = 0;
	while (i < main->map->info.width * main->map->info.height)
	{
		printf("%.0f ", main->map->vertices[i].y[0]);
		if ((int)main->map->vertices[i].x[0] + (int) main->map->vertices[0].x[0] == 0)
			printf("\n");
		// if (main->map->vertices[i].colors[0] != 0)
		// 	printf("%d|    |", main->map->vertices[i].colors[0]);
		i++;
	}
}