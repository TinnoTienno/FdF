/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:53:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:50:44 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	fdf_put_pixel(t_main *main, t_vertex *vertex)
{
	char	*dst;

	if (vertex->val[1][0] < DEFAULT_WINDOW_BORDER || vertex->val[1][1] \
		< DEFAULT_WINDOW_BORDER || vertex->val[1][0] >= main->finfo.w_width \
			- DEFAULT_WINDOW_BORDER || vertex->val[1][1] \
			>= main->finfo.w_height - DEFAULT_WINDOW_BORDER)
		return ;
	if (main->image_z[(int) round(vertex->val[1][1])][(int) \
		round(vertex->val[1][0])] > (int) round(vertex->val[1][2]))
		return ;
    
	dst = main->image.addr + (int) round(vertex->val[1][1]) * \
		main->image.line_length + (int) round(vertex->val[1][0]) * \
			(main->image.bits_per_pixel / 8);
	if (main->event.colormode == 0)
		*(unsigned int *)dst = vertex->color[0];
	else
		*(unsigned int *)dst = vertex->color[1];
	main->image_z[(int) round(vertex->val[1][1])][(int) \
	round(vertex->val[1][0])] = (int) round(vertex->val[1][2]);
}
