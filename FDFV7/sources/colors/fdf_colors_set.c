/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:32:14 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/20 15:30:23 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_color_parsing(t_main *main)
{
	int	y;
	int	x;

	y = 0;
	while (y < main->map.info.height)
	{
		x = 0;
		while (x < main->map.info.width)
		{
			main->display[y][x].color1 = main->map.vertices[y][x].color;
			main->display[y][x].color2 = fdf_color2_vertex(main->map.vertices[y][x].z, main); 
		}
	}
}