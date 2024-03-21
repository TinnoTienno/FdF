/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:07:35 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/20 18:10:21 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	fdf_colors_adjustement(t_main *main)
// {
// 	// printf("info color : %x, depth : %d\n", main->colors.color_deepsea, main->map.info.zmin);
// 	// printf("info color : %x, depth : %f\n", main->colors.color_sealevel,main->colors.sea_level);
// 	// printf("info color : %x, depth : %f\n",main->colors.color_beach,main->colors.beach_level);
// 	// printf("info color : %x, depth : %f\n",main->colors.color_moutain,main->colors.moutain_level);
// 	// printf("info color : %x, depth : %d\n",main->colors.color_top,main->map.info.zmax);
// }

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
	main->colors.beach_level = 5;
	main->colors.greenland_level = main->map.info.zmax / 100 * 1;
	main->colors.moutain_level = main->map.info.zmax / 100 * 30;
	main->colors.top_level = main->map.info.zmax;
	// fdf_colors_adjustement(main);
}