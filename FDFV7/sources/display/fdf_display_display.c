/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:10:33 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/17 17:14:27 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display_display(t_main *main)
{
	int y;
	int x;

	y = 0;
	while (y < main->map.info.height)
		{
			x = 0;
			while (x < main->map.info.width)
			{
				printf("%x ", main->display[y][x].color2);
				x++;
			}
			printf("\n");
			y++;
		}
}