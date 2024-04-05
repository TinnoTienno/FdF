/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_z_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:07:54 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/02 17:15:32 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_image_z_clean(t_main *main)
{
	int y;
	int x;

	y = -1;
	while (++y < main->file_info.window_height)
	{
		x = -1;
		while (++x < main->file_info.window_width)
			main->image_z[y][x] = -2147483648;
	}
}