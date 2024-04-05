/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_vertices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:04:11 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/02 15:06:32 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_print_vertices(t_main *main, char c)
{
	int	x;
	int	y;

	y = 0;
	printf("Display de %c :\n", c);
	if (c == 'x')
	{
		while (y < main->minfo.height)
		{
			x = 0;
			while (x < main->minfo.width)
			{
				printf("%.0f ", main->vertices[y][x].val[0][0]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
	else if (c == 'y')
	{
		while (y < main->minfo.height)
		{
			x = 0;
			while (x < main->minfo.width)
			{
				printf("%.0f ", main->vertices[y][x].val[0][1]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
	else if (c == 'z')
	{
		while (y < main->minfo.height)
		{
			x = 0;
			while (x < main->minfo.width)
			{
				printf("%.0f ", main->vertices[y][x].val[0][2]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
	else if (c == 'c')
	{
		while (y < main->minfo.height)
		{
			x = 0;
			while (x < main->minfo.width)
			{
				printf("%x ", main->vertices[y][x].color[0]);
				x++;
			}
			printf("\n");
			y++;
		}
	}
	
}