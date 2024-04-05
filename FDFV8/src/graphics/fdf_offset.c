/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:31:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 00:33:05 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_offsetx(t_main *main, double x)
{
	int res;

	res = x + main->image.center_x;
	return (res);
}

int	fdf_offsety(t_main *main, double y)
{
	int res;

	res = y + main->image.center_y * 1.4;
	return (res);
}