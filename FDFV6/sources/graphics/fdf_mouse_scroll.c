/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_scroll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:00:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 21:57:09 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_mouse_scroll(int button, int x, int y, t_main *main)
{
	(void) x;
	(void) y;
	// printf("%f . ", main->scale.indexing);
	if (button == 4)
		main->scale.indexing = 1.1 * main->scale.indexing;
	else if (button == 5)
		main->scale.indexing /= 1.1 * main->scale.indexing;
	printf("%f . ", main->scale.indexing);
	return (0);
}