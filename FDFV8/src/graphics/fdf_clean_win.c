/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:41:47 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/04 19:33:14 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_clean_win(t_main *main)
{
	int		x;
	int		y;
	char 	*dst;

	y = -1;
	while (++y < main->finfo.w_height)
	{
		x = -1;
		while (++x < main->finfo.w_width)
		{
			if (main->image_z[y][x] != -2147483648)
			{
				dst = main->image.addr + y * main->image.line_length + x * (main->image.bits_per_pixel / 8);
				*(unsigned int*)dst = 0;
				main->image_z[y][x] = -2147483648;
			}
		}
	}
}