/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_altitudemod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:51:40 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/25 15:35:14 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_altitudemod(t_main *main, int i)
{
	int x;
	int y;
	double range;
	
	y = 0;
	range = main->map.info.zmax - main->map.info.zmin;
	while (y < main->map.info.height)
	{
		x = 0;
		while (x < main->map.info.width)
		{
			VALUE(VERTEX(x, y), 1, 2) = VALUE(VERTEX(x, y), 1, 2) * (100 + i) / 100;
			x++;
		}
		y++;
	}
}