/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_vertex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:14:26 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 21:18:19 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display_vertex(t_main *main, int y, int x)
{
	printf("vertex : \np : %p\n", &main->map.vertices[y][x]);
	printf("x : %.0f\ny : %.0f\nz : %.0f\ncolor : %x\n", main->map.vertices[y][x].x, main->map.vertices[y][x].y, main->map.vertices[y][x].z, main->map.vertices[y][x].color);
}