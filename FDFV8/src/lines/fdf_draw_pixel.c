/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:30:25 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:39:35 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_draw_pixel(t_main *main, int x, int y, int color)
{
	char	*dst;

	dst = main->image.addr + y * main->image.line_length \
		+ x * (main->image.bits_per_pixel / 8);
		*(unsigned int *)dst = color;
}
