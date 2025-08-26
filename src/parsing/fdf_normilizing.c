/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_normilizing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:55:44 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:03:17 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex	**fdf_normilizing(t_main *main)
{
	int			x;
	int			y;
	double		widthcenter;
	double		heightcenter;
	t_vertex	**vertices;

	widthcenter = (main->minfo.width - 1) / 2;
	heightcenter = (main->minfo.height - 1) / 2;
	vertices = main->vertices;
	y = 0;
	while (y < main->minfo.height)
	{
		x = 0;
		while (x < main->minfo.width)
		{
			vertices[y][x].val[0][1] = vertices[y][x].val[0][1] - heightcenter;
			vertices[y][x].val[0][0] = vertices[y][x].val[0][0] - widthcenter;
			x++;
		}
		y++;
	}
	return (vertices);
}
