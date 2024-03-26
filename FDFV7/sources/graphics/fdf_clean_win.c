/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:34:45 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/26 17:00:38 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_clean_win(t_main *main)
{
	int		x;
	int		y;


	y = -1;
	while (y < main->file_info.window_height)
	{
		x = -1;
		while (++x < main->file_info.window_width)
			my_mlx_pixel_put(main, x, y, 0);
		++y;
	}
}