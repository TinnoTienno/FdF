/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:48:50 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/27 12:04:08 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(t_main *main, char *error_message)
{
	int	y;
	t_parsing *tmp;
	
	if (error_message && error_message[0])
		fd_printf(2, "%s", error_message);
	if (main->file_info.args)
		free (main->file_info.args);
	if (main->file_info.filename)
		free (main->file_info.filename);
	if (main->list)
	{
		while (main->list)
		{
			tmp = main->list->next;
			free (main->list->line);
			free (main->list);
			main->list = tmp;
		}
	}
	if (main->map.vertices)
	{
		y = -1;
		while (++y < main->map.info.height)
			free (main->map.vertices[y]);
		free (main->map.vertices);
	}
	if (main->image.img)
		mlx_destroy_image(main->mlx, main->image.img);
	if (main->win)
		mlx_destroy_window(main->mlx, main->win);
	if (main->mlx)
	{
		mlx_destroy_display(main->mlx);
		free (main->mlx);
	}
	if (main->display)
	{
		y = -1;
		while (++y < main->map.info.height)
			free (main->display[y]);
		free (main->display);
	}
	if (main->image_z)
		fdf_image_z_free(main);
	if (error_message && error_message[0])
		exit (EXIT_FAILURE);
}