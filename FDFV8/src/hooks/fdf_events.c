/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:34:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/04 21:42:01 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_cmod(t_main *main)
{
	if (main->event.colormode == 0)
		main->event.colormode = 1;
	else
		main->event.colormode = 0;
}

static void	fdf_vmod(t_main *main)
{
	if (main->event.viewmode == 0)
		main->event.viewmode = 1;
	else
		main->event.viewmode = 0;
	main->event.x_angle = 0;
	main->event.z_angle = 0;
}
static void	fdf_lmod(t_main *main)
{
	if (main->event.linemode == 0)
		main->event.linemode = 1;
	else
		main->event.linemode = 0;
}

void	fdf_event(t_main *main, int c)
{
	if (c == 'c')
		fdf_cmod(main);
	else if (c == 'v')
		fdf_vmod(main);
	else if (c == 'l')
		fdf_lmod(main);
}