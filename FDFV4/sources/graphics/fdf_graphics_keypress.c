/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics_keypress.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:32:22 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/10 14:57:22 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_graphics_keypress(int keycode, t_vars *vars)
{
	// printf("%d\n", keycode);
	if (keycode == ESC_KEY)
		fdf_graphics_close(vars);
	if (keycode == S_KEY)
		fdf_status(S_KEY, vars);
	return (0);
}