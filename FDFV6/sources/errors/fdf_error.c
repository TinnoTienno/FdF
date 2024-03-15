/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:37:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 20:18:31 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(t_main *main, char *str)
{
	fd_printf(2, "%s", str);
	if (main)
	{
		if (main->arg)
			free (main->arg);
		if (main->map)
		{
			if (main->map->vertices)
				free (main->map->vertices);
			free (main->map);
		}
		printf("%p %p\n", main->mlx, main->image.img);
		if (main->image.img)
			mlx_destroy_image(main->mlx, main->image.img);
		if (main->win)
			mlx_destroy_window(main->mlx, main->win);
		if (main->mlx)
		{
			mlx_destroy_display(main->mlx);
			free(main->mlx);
		}
	}
	if (str[0])
		exit (EXIT_FAILURE);
}
