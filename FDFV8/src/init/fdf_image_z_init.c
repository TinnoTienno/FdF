/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_z_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:50:03 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 18:52:49 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_image_z_init(t_main *main)
{
	int	y;
	int	x;

	main->image_z = ft_calloc(main->finfo.w_height, sizeof(int *));
	if (!main->image_z)
		fdf_error(main, "Error in fdf_image_z_init function : Malloc \n");
	y = -1;
	while (++y < main->finfo.w_height)
	{
		main->image_z[y] = ft_calloc(main->finfo.w_width, sizeof(int));
		if (!main->image_z[y])
			fdf_error(main, "Error in fdf_image_z_init function : Malloc \n");
		x = -1;
		while (++x < main->finfo.w_width)
			main->image_z[y][x] = -2147483648;
	}
}
