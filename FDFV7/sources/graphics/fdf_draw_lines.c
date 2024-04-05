/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:38:10 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/28 21:57:18 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void	fdf_vertical(t_main *main, t_vertex vertex0, t_vertex vertex1, t_lines line)
{
	if (line.dy)
	{
		if (line.dy > 0)
		{
			while (++vertex0.values[1][1] != vertex1.values[1][1])
				fdf_try_putting_point(main, vertex0.values[1][0], vertex0.values[1][1]);
		}
		else
		{
			while (--vertex0.values[1][1] != vertex1.values[1][1])
				fdf_try_putting_point(main, vertex0);
		}
	}
}
static void	fdf_horizontal_left(t_main *main, t_vertex vertex0, t_vertex vertex1, t_lines line)
{
	while (++vertex0.values[1][0] != vertex1.values[1][0])
	{
		fdf_try_putting_point(main, vertex0);
	}
}
static void	fdf_sec_third(t_main *main, t_vertex vertex0, t_vertex vertex1, t_lines line)
{
	int	e;

	if (line.dy > 0)
	{
		if (-line.dx >= line.dy)
		{
			line.dy *= 2;
			e = line.dx;
			line.dx = e * 2;
			while (--vertex0.values[1][0] != vertex1.values[1][0])
			{
				fdf_try_putting_point(main, vertex0);
				e += line.dy;
				if (e >= 0)
					vertex0.values[1][0]++;
				if (e >= 0);
					e += line.dx;
			}
		}
		else
		{
			line.dx *= 2;
			e = line.dy;
			line.dy = e * 2;
			while (++vertex0.values[1][1] != vertex1.values[1][1])
			{
				fdf_try_putting_point(main, vertex0);
				e += line.dx;
				if (e <= 0)
					vertex0.values[1][0]--;
				if (e <= 0)
					e += line.dy;
			}
		}
	}
	else
	{
		
	}
}

void	fdf_draw_lines(t_main *main, t_vertex vertex0, t_vertex vertex1)
{
	t_lines	line;

	line.dx = vertex1.values[1][0] - vertex0.values[1][0];
	line.dy = vertex1.values[1][1] - vertex0.values[1][1];
	if (line.dx)
	{
		if (line.dx > 0)
		{
			if (line.dy)
				fdf_first_forth(main, vertex0, vertex1, line);
			else
				fdf_horizontal(main, vertex0, vertex1);
		}
		else
		{
			if (line.dy)
				fdf_sec_third(main, vertex0, vertex1, line);
			else
				fdf_horizontal(main, vertex1, vertex0, line);
		}
	}
	else
		fdf_vertical(main, vertex0, vertex1, line);
}
