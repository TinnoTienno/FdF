/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color_shift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:36:52 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/20 17:37:50 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	fdf_color_shift(double index, int color0, int color1)
{
	int	res;

	res = (int)(((color1 & 0xFF) - (color0 & 0xFF)) * (index) + (color0 & 0xFF)) & 0xff; 
	res += (int)(((color1 & 0xFF00) - (color0 & 0xFF00)) * (index) + (color0 & 0xFF00)) & 0xff00; 
	res += (int)(((color1 & 0xFF0000) - (color0 & 0xFF0000)) * (index) + (color0 & 0xFF0000)) & 0xff0000;
	return (res);
}