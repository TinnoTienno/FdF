/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics_keypress.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:32:22 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 18:19:30 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_graphics_keypress(int keycode, t_main *main)
{
	// printf("%d\n", keycode);
	if (keycode == ESC_KEY)
		fdf_graphics_close(main);
	return (0);
}