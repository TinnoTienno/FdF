/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:43:28 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/26 17:37:41 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_vertex(t_main *main, t_vertex vertex)
{
	if (main->event.color_mode == 0)
	{
		fdf_put_pixel(main, (int) vertex.values[1][0], (int) vertex.values[1][1], vertex.color);
	}
	else
	{
		fdf_put_pixel(main, (int) vertex.values[1][0], (int) vertex.values[1][1], vertex.colormod);
	}
	main->image_z[(int) vertex.values[1][1]][(int) vertex.values[1][0]] = (int) vertex.values[1][2];
}