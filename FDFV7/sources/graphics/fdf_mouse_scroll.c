/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_scroll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:10:24 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/21 16:32:47 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_mouse_scroll(int button, int x, int y, t_main *main)
{
	(void) x;
	(void) y;
	if (button == 4)
		main->event.scaling = main->event.scaling * 1.1;
	else if (button == 5)
		main->event.scaling = main->event.scaling / 1.1;
	return (0);
}