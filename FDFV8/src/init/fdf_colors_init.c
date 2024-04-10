/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:09:48 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:41:38 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_color_shift(double index, int color0, int color1)
{
	int	res;

	res = (int)(((color1 & 0xFF) - (color0 & 0xFF)) \
		* (index) + (color0 & 0xFF)) & 0xff;
	res += (int)(((color1 & 0xFF00) - (color0 & 0xFF00)) \
		* (index) + (color0 & 0xFF00)) & 0xff00;
	res += (int)(((color1 & 0xFF0000) - (color0 & 0xFF0000)) \
		* (index) + (color0 & 0xFF0000)) & 0xff0000;
	return (res);
}

static int	fdf_color2_earth(t_main *main, t_vertex vertex)
{
	int			color;
	double		index;
	double		z;
	t_colors	c;

	color = 0;
	index = 0;
	c = main->colors;
	z = vertex.val[0][2];
	if (z >= c.beach_level && z <= c.greenland_level)
	{
		index = (z - c.beach_level) / (c.greenland_level - c.beach_level);
		color = fdf_color_shift(index, c.color_beach, c.color_greenland);
	}
	else if (z >= c.greenland_level && z <= c.moutain_level)
	{
		index = (z - c.greenland_level) / (c.moutain_level - c.greenland_level);
		color = fdf_color_shift(index, c.color_greenland, c.color_moutain);
	}
	else if (z >= c.moutain_level && z <= c.top_level)
	{
		index = (z - c.moutain_level) / (c.top_level - c.moutain_level);
		color = fdf_color_shift(index, c.color_moutain, c.color_top);
	}
	return (color);
}

static int	fdf_color2_vertex(t_main *main, t_vertex vertex)
{
	int			color;
	double		index;
	double		z;
	t_colors	c;

	color = 0;
	index = 0;
	c = main->colors;
	z = vertex.val[0][2];
	if (z >= c.bottom_level && z <= c.shallow_sea_level)
	{
		index = (z - c.bottom_level) / (c.shallow_sea_level - c.bottom_level);
		color = fdf_color_shift(index, c.color_deepsea, c.color_shallowsea);
	}
	else if (z >= c.shallow_sea_level && z <= c.beach_level)
	{
		index = (z - c.shallow_sea_level) / \
			(c.beach_level - c.shallow_sea_level);
		color = fdf_color_shift(index, c.color_shallowsea, c.color_beach);
	}
	else
		color = fdf_color2_earth(main, vertex);
	return (color);
}

static void	fdf_color_parsing(t_main *main)
{
	int			y;
	int			x;
	t_vertex	**vertices;

	y = -1;
	vertices = main->vertices;
	while (++y < main->minfo.height)
	{
		x = -1;
		while (++x < main->minfo.width)
		vertices[y][x].color[1] = fdf_color2_vertex(main, vertices[y][x]);
	}
}

void	fdf_colors_init(t_main *main)
{
	main->colors = main->colors;
	main->colors.color_deepsea = 0x1F2684;
	main->colors.color_shallowsea = 0x56C9FB;
	main->colors.color_beach = 0xfee9a8;
	main->colors.color_greenland = 0xafd46b;
	main->colors.color_moutain = 0xb28556;
	main->colors.color_top = 0xFFFFFF;
	main->colors.bottom_level = main->minfo.zmin[0];
	main->colors.shallow_sea_level = main->minfo.zmin[0] / 1000 * 3 ;
	if (main->colors.shallow_sea_level == main->colors.bottom_level)
		main->colors.bottom_level -= 1;
	main->colors.beach_level = 5;
	main->colors.greenland_level = main->minfo.zmax[0] / 100 * 1;
	main->colors.moutain_level = main->minfo.zmax[0] / 100 * 30;
	main->colors.top_level = main->minfo.zmax[0];
	fdf_color_parsing(main);
}
