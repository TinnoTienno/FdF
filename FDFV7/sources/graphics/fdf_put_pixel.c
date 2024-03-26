/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:53:31 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/26 16:55:15 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_put_pixel(t_main *main, int x, int y, int color)
{
	char 	*dst;
	
	if (x < DEFAULT_WINDOW_BORDER || y < DEFAULT_WINDOW_BORDER || x >= main->file_info.window_width - DEFAULT_WINDOW_BORDER || y >= main->file_info.window_height - DEFAULT_WINDOW_BORDER)
		return ;
	dst = main->image.addr + (int) y * main->image.line_length + (int) x * (main->image.bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}