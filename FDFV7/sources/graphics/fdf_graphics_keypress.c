/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics_keypress.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:32:22 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/25 15:23:50 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_graphics_keypress(int keycode, t_main *main)
{
	if (keycode == XK_Escape)
		fdf_graphics_close(main);
	else if (keycode == XK_c || keycode == XK_C)
		fdf_event(main, 'c');
	else if (keycode == XK_V)
		fdf_event(main, 'v');
	else if (keycode == XK_L)
		fdf_event(main, 'l');
	else if (keycode == XK_Up || keycode == XK_Down || keycode == XK_Left || keycode == XK_Right)
		fdf_move(main, keycode);
	else if (keycode == XK_KP_Up)
		fdf_altitudemod(main, 1);
	else if (keycode == XK_KP_Down)
		fdf_altitudemod(main, -1);
	return (0);
}