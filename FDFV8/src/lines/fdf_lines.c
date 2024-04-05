/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:42:29 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 18:54:09 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_lines_next(t_main *main)
{
	int	y;
	int	x;

	y = -1;
	while (++y < main->minfo.height)
	{
		x = -1;
		while (++x < main->minfo.width)
		{
			if (main->event.linemode == 2 && x < main->minfo.width \
				- 1 && y < main->minfo.height - 1)
				fdf_draw_line(main, &main->vertices[y][x], \
					&main->vertices[y + 1][x + 1]);
			if (x < main->minfo.width - 1)
				fdf_draw_line(main, &main->vertices[y][x], \
					&main->vertices[y][x + 1]);
			if (y < main->minfo.height - 1)
				fdf_draw_line(main, &main->vertices[y][x], \
					&main->vertices[y + 1][x]);
		}
	}
}

void	fdf_lines(t_main *main)
{
	if (main->event.linemode == 1)
		return ;
	fdf_lines_next(main);
}
