/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:20:47 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:00:20 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_mapping(t_main *main)
{
	fdf_parsing(main);
	fdf_map_info(main);
	main->vertices = ft_calloc(main->minfo.height, sizeof(t_vertex *));
	if (!main->vertices)
		fdf_error(main, "Error in fdf_mapping : Malloc\n");
	fdf_vertices(main);
	fdf_freeparsing(main);
	main->vertices = fdf_normilizing(main);
}
