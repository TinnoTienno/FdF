/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:22:58 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/21 16:35:39 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_main *main, int x, int y, int color)
{
	char 	*dst;

	if (x < DEFAULT_WINDOW_BORDER || y < DEFAULT_WINDOW_BORDER || x >= main->file_info.window_width - DEFAULT_WINDOW_BORDER || y >= main->file_info.window_height - DEFAULT_WINDOW_BORDER)
		return ;
	dst = main->image.addr + y * main->image.line_length + x * (main->image.bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}