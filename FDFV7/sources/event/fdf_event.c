/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:45:09 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/21 15:46:22 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_cmod(t_main *main)
{
	if (main->event.color_mode == 0)
		main->event.color_mode = 1;
	else
		main->event.color_mode = 0;	
}
static void	fdf_vmod(t_main *main)
{
	if (main->event.view_mode == 0)
		main->event.view_mode = 1;
	else
		main->event.view_mode = 0;
	
}
static void	fdf_lmod(t_main *main)
{
	if (main->event.line_mode == 0)
		main->event.line_mode = 1;
	else
		main->event.line_mode = 0;
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