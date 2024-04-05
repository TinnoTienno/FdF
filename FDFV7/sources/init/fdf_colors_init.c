/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:07:35 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/04 15:30:02 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_color_parsing(t_main *main)
{
	int	y;
	int	x;
	t_vertex **vertices;

	y = -1;
	vertices = main->map.vertices;
	while (++y < main->map.info.height)
	{
		x = -1;
		while (++x < main->map.info.width)
		vertices[y][x].colormod = fdf_color2_vertex(main, vertices[y][x]);
	}
}

void	fdf_colors_init(t_main *main)
{
	main->colors.color_deepsea = 0x1F2684;
	main->colors.color_shallowsea = 0x56C9FB;
	main->colors.color_beach = 0xfee9a8;
	main->colors.color_greenland = 0xafd46b;
	main->colors.color_moutain = 0xb28556;
	main->colors.color_top = 0xFFFFFF;
	main->colors.bottom_level = main->map.info.zmin;
	main->colors.shallow_sea_level = main->map.info.zmin / 1000 * 3 ;
	if (main->colors.shallow_sea_level == main->colors.bottom_level)
		 main->colors.bottom_level -= 1;
	main->colors.beach_level = 5;
	main->colors.greenland_level = main->map.info.zmax / 100 * 1;
	main->colors.moutain_level = main->map.info.zmax / 100 * 30;
	main->colors.top_level = main->map.info.zmax;
	fdf_color_parsing(main);
}