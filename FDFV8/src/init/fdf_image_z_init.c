/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_z_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:50:03 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/03 13:58:16 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_image_z_init(t_main *main)
{
	int	y;
	int	x;

	main->image_z = malloc(sizeof(int *) * main->finfo.w_height);
	y = -1;
	while (++y < main->finfo.w_height)
	{
		main->image_z[y] = ft_calloc(main->finfo.w_width, sizeof(int));
		x = -1;
		while (++x < main->finfo.w_width)
			main->image_z[y][x] = -2147483648;
	}
}