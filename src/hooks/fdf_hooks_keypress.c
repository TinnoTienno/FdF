/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_keypress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:26:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:43:32 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>
#include <math.h>

static int	fdf_is_mod(int keycode, t_main *main)
{
	if (keycode == XK_c || keycode == XK_C)
	{
		fdf_event(main, 'c');
		return (1);
	}
	else if (keycode == XK_V || keycode == XK_v)
	{
		fdf_event(main, 'v');
		return (1);
	}
	else if (keycode == XK_L || keycode == XK_l)
	{
		fdf_event(main, 'l');
		return (1);
	}
	return (0);
}

static int	fdf_is_arrow(int keycode, t_main *main)
{
	if (keycode == XK_Down)
	{
		main->image.center_y += main->finfo.w_height / 100;
		return (1);
	}
	else if (keycode == XK_Up)
	{
		main->image.center_y -= main->finfo.w_height / 100;
		return (1);
	}
	else if (keycode == XK_Right)
	{
		main->image.center_x += main->finfo.w_width / 100;
		return (1);
	}
	else if (keycode == XK_Left)
	{
		main->image.center_x -= main->finfo.w_width / 100;
		return (1);
	}
	return (0);
}

int	fdf_hooks_keypress(int keycode, t_main *main)
{
	if (keycode == XK_Escape)
		fdf_hooks_close(main);
	else if (fdf_is_mod(keycode, main) == 1)
		return (1);
	else if (fdf_is_arrow(keycode, main) == 1)
		return (2);
    else if (keycode == XK_space)
        main->event.rotating = true;
	else if (keycode == XK_KP_Up)
	{
		main->event.z_mod += 1;
		return (3);
	}
	else if (keycode == XK_KP_Down)
	{
		main->event.z_mod -= 1;
		return (3);
	}
	else if (fdf_angle(keycode, main) == 1)
		return (1);
	return (0);
}
