/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:53:34 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/25 15:41:24 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_mapping(t_main *main)
{
	fdf_parsing(main);
	fdf_map_info(main);
	if (main->map.info.total == 0)
		fdf_error(main, "error in fdf_mapping function : map too small\n");
	main->map.vertices = ft_calloc(sizeof(t_vertex *), main->map.info.height);
	if (!main->map.vertices)
		fdf_error(main, "Error in fdf_mapping function : Malloc unitialized\n");
	fdf_vertices(main);
	fdf_normilizing(main);
	// fdf_colors_set(main);
	// fdf_display_map(main, 'y');
}