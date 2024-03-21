/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color2_vertex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:22:42 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/20 18:02:50 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_color2_vertex(double z, t_main *main)
{
	int color;
	double	index;

	color = 0;
	index = 0;

	if (z >= main->colors.bottom_level && z <= main->colors.shallow_sea_level)
	{
		index = (z - main->colors.bottom_level) / (main->colors.shallow_sea_level - main->colors.bottom_level);
		color = fdf_color_shift(index, main->colors.color_deepsea, main->colors.color_shallowsea);
	}
	else if (z >= main->colors.shallow_sea_level && z <= main->colors.beach_level)
	{
		index = (z - main->colors.shallow_sea_level) / (main->colors.beach_level - main->colors.shallow_sea_level);
		color = fdf_color_shift(index, main->colors.color_shallowsea, main->colors.color_beach);
	}
	else if (z >= main->colors.beach_level && z <= main->colors.greenland_level)
	{
		index = (z - main->colors.beach_level) / (main->colors.greenland_level - main->colors.beach_level);
		color = fdf_color_shift(index, main->colors.color_beach, main->colors.color_greenland);
	}
	else if (z >= main->colors.greenland_level && z <= main->colors.moutain_level)
	{
		index = (z - main->colors.greenland_level) / (main->colors.moutain_level - main->colors.greenland_level);
		color = fdf_color_shift(index, main->colors.color_greenland, main->colors.color_moutain);
	}
	else if (z >= main->colors.moutain_level && z <= main->colors.top_level)
	{
		index = (z - main->colors.moutain_level) / (main->colors.top_level - main->colors.moutain_level);
		color = fdf_color_shift(index, main->colors.color_moutain, main->colors.color_top);
	}
	return (color);
}