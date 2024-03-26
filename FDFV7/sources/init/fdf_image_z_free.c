/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_z_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:29:41 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/26 16:33:42 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_image_z_free(t_main *main)
{
	int	y;

	y = -1;
	while (++y < main->file_info.window_height)
		free (main->image_z[y]);
	free (main->image_z);
}