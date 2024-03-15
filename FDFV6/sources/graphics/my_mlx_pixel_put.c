/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:22:58 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 20:39:36 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char 	*dst;

	if (x < 0 || y < 0 || x >= FDF_WINDOW_WIDTH || y >= FDF_WINDOW_HEIGHT)
		return ;
	dst = data->addr + y * data->line_length + x * (data->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}