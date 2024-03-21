/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:35:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/17 19:04:21 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_map_info(t_main *main)
{
	t_parsing *tmp;
	
	main->map.info.width = ft_countword(main->list->line, ' ');
	tmp = main->list;
	main->map.info.height = 0;
	while (tmp->next)
	{
		main->map.info.height++;
		tmp = tmp->next;
	}
	main->map.info.zmin = ft_atoi(main->list->line);
	main->map.info.zmax = main->map.info.zmin;
	main->map.info.total = main->map.info.height * main->map.info.width;
	// printf("Map info : \nwidth : %d\nheight : %d\ntotal : %d\nzmin : %d\n", main->map.info.width, main->map.info.height, main->map.info.total, main->map.info.zmax);
}