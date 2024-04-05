/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 21:14:44 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/04 21:55:13 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <X11/keysym.h>


static void	fdf_w(t_main *main)
{
	if (main->event.viewmode == 0)
	{
		if (main->event.x_angle > 1)
			main->event.x_angle -= 1;
		else
			main->event.x_angle = 360;
	}
	else
	{
		if (main->event.x_angle == 90)
			main->event.x_angle = 360;
		else
			main->event.x_angle -= 90;
	}
}

static void	fdf_a(t_main *main)
{
	if (main->event.viewmode == 0)
	{
		if (main->event.z_angle < 360 - 1)
			main->event.z_angle += 1;
		else
			main->event.z_angle = 0;
	}
	else
	{
		if (main->event.z_angle == 280)
			main->event.z_angle = 0;
		else
			main->event.z_angle += 90;
	}
}
static void	fdf_s(t_main *main)
{
	if (main->event.viewmode == 0)
	{
		if (main->event.x_angle < 359)
			main->event.x_angle += 1;
		else
			main->event.x_angle = 0;
	}
	else
	{
		if (main->event.x_angle == 280)
			main->event.x_angle = 0;
		else
			main->event.x_angle += 90;
	}
}
static void	fdf_d(t_main *main)
{
	if (main->event.viewmode == 0)
	{
		if (main->event.z_angle > 1)
			main->event.z_angle -= 1;
		else
			main->event.z_angle = 360;
	}
	else
	{
		if (main->event.z_angle == 90)
			main->event.z_angle = 360;
		else
			main->event.z_angle -= 90;
	}
}
int	fdf_angle(int keycode, t_main *main)
{
	if (keycode == XK_w || keycode == XK_W)
		fdf_w(main);
	else if (keycode == XK_a || keycode == XK_A)
		fdf_a(main);
	else if (keycode == XK_s || keycode == XK_S)
		fdf_s(main);
	else if (keycode == XK_d || keycode == XK_D)
		fdf_d(main);
	return (0);
}