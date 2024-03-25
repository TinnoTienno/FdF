/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:48:06 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/25 15:21:24 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_move(t_main *main, int keycode)
{
	if (keycode == XK_Up)
		main->image.center_y += main->file_info.window_height / 100;
	else if (keycode == XK_Down)
		main->image.center_y -= main->file_info.window_height / 100;
	else if (keycode == XK_Left)
		main->image.center_x += main->file_info.window_width / 100;
	else if (keycode == XK_Right)
		main->image.center_x -= main->file_info.window_width / 100;
}