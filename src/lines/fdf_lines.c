/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 00:42:29 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:40:52 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*fdf_lines_next(void *ptr)
{
	struct arg_struct *args = ptr;
    int y = args->min;
    for (; y < args->max; y++)
    {
	    for (int x = 0; x < args->main->minfo.width; x++)
	    {
			if (args->main->event.linemode == 2 && x < \
				args->main->minfo.width - 1 && y < args->main->minfo.height - 1)
				fdf_draw_line(args->main, &args->main->vertices[y][x], \
					&args->main->vertices[y + 1][x + 1]);
			if (x < args->main->minfo.width - 1)
				fdf_draw_line(args->main, &args->main->vertices[y][x], \
					&args->main->vertices[y][x + 1]);
			if (y < args->main->minfo.height - 1)
				fdf_draw_line(args->main, &args->main->vertices[y][x], \
					&args->main->vertices[y + 1][x]);
		}
    }
    pthread_exit(NULL);
    return  NULL;
}

void	fdf_lines(t_main *main)
{
	if (main->event.linemode == 1)
		return ;
    fdf_threads_init(main, fdf_lines_next);
}
