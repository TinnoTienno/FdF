/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics_keypress.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:32:22 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/26 13:17:05 by eschussl         ###   ########.fr       */
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
		main->event.z_mod += 1;
	else if (keycode == XK_KP_Down)
		main->event.z_mod -= 1;
	else if (keycode == XK_w || keycode == XK_W)
	{
		if (main->event.x_angle > 5 * (M_PI / 180))
			main->event.x_angle -= 5 * (M_PI / 180);
		else
			main->event.x_angle = 360 * (M_PI / 180);
	}
	else if (keycode == XK_a || keycode == XK_A)
		if (main->event.z_angle < 355 * (M_PI / 180))
			main->event.z_angle += 5 * (M_PI / 180);
		else
			main->event.z_angle = 0 * (M_PI / 180);
	else if (keycode == XK_s || keycode == XK_S)
		if (main->event.x_angle < 355 * (M_PI / 180))
			main->event.x_angle += 5 * (M_PI / 180);
		else
			main->event.x_angle = 0 * (M_PI / 180);
	else if (keycode == XK_d || keycode == XK_D)
	{
		if (main->event.z_angle > 5 * (M_PI / 180))
			main->event.z_angle -= 5 * (M_PI / 180);
		else
			main->event.z_angle = 360 * (M_PI / 180);
	}
	return (0);
}
