/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_push_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:39:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:46:00 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_push_loop(t_main *main)
{
    static int current_angle = 0;

    if (main->event.rotating == true)
    {
        if (current_angle >= 360)
        {
            current_angle = 0;
            main->event.rotating = false;
        }
        else
        {
            current_angle += 1;
            main->event.scaling = main->event.scaling * 1.01;
            main->event.z_angle = current_angle;
        }
    }
	fdf_clean_win(main);
	fdf_threads_init(main, fdf_thread_exec);
	fdf_lines(main);
	mlx_put_image_to_window(main->mlx, main->win, main->image.img, 0, 0);
	return (1);
}
