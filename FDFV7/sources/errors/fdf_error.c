/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:48:50 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 21:51:53 by eschussl         ###   ########.fr       */
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
		y = 0;
		while (y < main->map.info.height)
		{
			free (main->map.vertices[y]);
			y++;
		}
		free (main->map.vertices);
	}
	if (error_message && error_message[0])
	{
		exit (EXIT_FAILURE);
	}
}