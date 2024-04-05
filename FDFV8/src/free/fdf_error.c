/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:56:57 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/04 23:33:45 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_free_finfo(t_finfo *finfo)
{
	if (finfo->args)
		free (finfo->args);
	if (finfo->filename)
		free (finfo->filename);
	(void) finfo;
}
static void	fdf_free_graphics(t_main *main)
{
	int	y;
	
	if (main->image.img)
		mlx_destroy_image(main->mlx, main->image.img);
	if (main->win)
		mlx_destroy_window(main->mlx, main->win);
	if (main->mlx)
	{
		mlx_destroy_display(main->mlx);
		free (main->mlx);	
	}
	y = -1;
	if (main->image_z)
	{
		while (++y < main->finfo.w_height)
			free (main->image_z[y]);
		free (main->image_z);
	}
}
static void	fdf_free_vertices(t_main *main)
{
	int	y;
	
	if (main->vertices)
	{
		y = -1;
		while (++y < main->minfo.height)
		{
			if (main->vertices[y])
				free (main->vertices[y]);
		}
		free (main->vertices);
	}
}
void	fdf_error(t_main *main, char *error_message)
{
	if (error_message && error_message[0])
		fd_printf(2, "%s", error_message);
	fdf_free_graphics(main);
	fdf_free_vertices(main);
	fdf_free_finfo(&main->finfo);
	gnl(-1);
	if (error_message && error_message[0])
		exit (EXIT_FAILURE);
}