/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 00:07:35 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/17 00:11:51 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_colors_init(t_main *main)
{
	main->colors.sea_level = 0; 
	main->colors.beach_level = 10;
	main->colors.moutain_level = 50;
	main->colors.color_deepsea = 0x182640;
	main->colors.color_sealevel = 0x0089b3;
	main->colors.color_beach = 0xd68e5a;
	main->colors.color_moutain = 0x0a4a11;
	main->colors.color_top = 0xffffff;
}