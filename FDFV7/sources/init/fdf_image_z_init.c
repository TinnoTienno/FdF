/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_z_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:21:29 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/02 17:12:10 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_image_z_init(t_main *main)
{
	int y;
	int	x;
	
	main->image_z = malloc(sizeof(int*) * main->file_info.window_height);
	y = -1;
	while (++y < main->file_info.window_height)
	{
		main->image_z[y] = malloc(sizeof(int) * main->file_info.window_width);
		x = -1;
		while (++x < main->file_info.window_width)
			main->image_z[y][x] = -9999999;
	}
}