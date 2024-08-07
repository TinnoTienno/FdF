/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:06:51 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/25 13:57:48 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display_map(t_main *main, char c)
{
	int	x;
	int	y;

	y = 0;
	printf("Display de %c :\n", c);
	if (c == 'x')
	{
		while (y < main->map.info.height)
		{
			x = 0;
			while (x < main->map.info.width)
			{
				printf("%.0f ", main->map.vertices[y][x].values[0][0]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
	else if (c == 'y')
	{
		while (y < main->map.info.height)
		{
			x = 0;
			while (x < main->map.info.width)
			{
				printf("%.0f ", main->map.vertices[y][x].values[0][1]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
	else if (c == 'z')
	{
		while (y < main->map.info.height)
		{
			x = 0;
			while (x < main->map.info.width)
			{
				printf("%.0f ", main->map.vertices[y][x].values[0][2]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
	else if (c == 'c')
	{
		while (y < main->map.info.height)
		{
			x = 0;
			while (x < main->map.info.width)
			{
				printf("%x ", main->map.vertices[y][x].color);
				x++;
			}
			printf("\n");
			y++;
		}
	}
	
}