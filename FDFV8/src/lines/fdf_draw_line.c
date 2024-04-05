/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:31:11 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 13:24:31 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_line_2(t_main *main, t_vertex v1, t_vertex v2)
{
	int	dy;
	int	y1;

	dy = v2.val[1][1] - v1.val[1][1];
	y1 = v1.val[1][1];
	if (dy > 0)
	{
		while (v1.val[1][1] < v2.val[1][1])
		{
			fdf_trace_pixel();
			v1.val[1][1]++;
		}
	}
}
void	fdf_draw_line(t_main *main, t_vertex v1, t_vertex v2)
{
	int	dx;
	int	dy;

	dx = v2.val[1][0] - v1.val[1][0];
	if (dx != 0)
	{
		
	}
	else
	{
		dy = v2.val[1][1] - v1.val[1][1];
		if (dy != 0)
			fdf_draw_line_2(main, v1, v2);
	}
}
