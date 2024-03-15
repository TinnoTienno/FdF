/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_mapping.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:51:55 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 21:09:47 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	fdf_display_mapping(t_fdf_map *map)
{
	int i;
	
	i = 0;
	while (i < map->info.length * map->info.width)
	{
		printf ("%.0f ", map->vertices[i].z);
		if (map->vertices[i].colors != 0)
			printf ("%d ", map->vertices[i].colors);
		i++;
		if (i % map->info.length == 0)
			printf("\n");
	}
}