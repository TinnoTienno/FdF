/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:05:32 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/25 15:34:51 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_isometric(t_main *main)
{
	int y;
	int x;

	y = 0;
	while (y < main->map.info.height)
	{
		x = 0;
		while (x < main->map.info.width)
		{
			VALUE(VERTEX(x, y), 1, 0) = (VALUE(VERTEX(x, y), 0, 0) - VALUE(VERTEX(x, y), 0, 1)) * cos(M_PI / 6);
			VALUE(VERTEX(x, y), 1, 1) = (VALUE(VERTEX(x, y), 0, 0) + VALUE(VERTEX(x, y), 0, 1)) * sin(M_PI / 6) - VALUE(VERTEX(x, y), 1, 2);
			x++;
		}
		y++;
	}
}