/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_normalizing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:21:33 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 23:25:05 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_normilizing(t_main *main)
{
	int x;
	int y;
	double	widthcenter;
	double		heightcenter;
	
	widthcenter = (main->map.info.width - 1) / 2;
	heightcenter = (main->map.info.height - 1) / 2;
	y = 0;
	while (y < main->map.info.height)
	{
		x = 0;
		while (x < main->map.info.width)
		{
			main->map.vertices[y][x].y = main->map.vertices[y][x].y - heightcenter;
			main->map.vertices[y][x].x = main->map.vertices[y][x].x - widthcenter;
			x++;
		}
		y++;
	}
	
}