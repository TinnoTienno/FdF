/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_offset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:37:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/21 15:42:36 by eschussl         ###   ########.fr       */
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

	res = y + main->image.center_y;
	return (res);
}