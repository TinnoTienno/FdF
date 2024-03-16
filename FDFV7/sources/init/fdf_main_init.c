/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:15:37 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 23:20:20 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_main_init(t_main *main)
{
	main->file_info.args = NULL;
	main->file_info.args = NULL;
	main->file_info.window_border = 0;
	main->file_info.window_height = 0;
	main->file_info.window_width = 0;
	main->list= NULL;
	main->map.info.height = 0;
	main->map.info.width = 0;
	main->map.info.total = 0;
	main->map.info.zmax = 0;
	main->map.info.zmin = 0;
	main->map.vertices = NULL;
	main->mlx = NULL;
	main->win = NULL;
}
