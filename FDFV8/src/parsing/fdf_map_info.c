/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:16:21 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/02 14:54:09 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_map_info(t_main *main)
{
	t_parsing *tmp;
	
	main->minfo.width = ft_countword(main->parsing->line, ' ');
	tmp = main->parsing;
	main->minfo.height = 0;
	while (tmp->next)
	{
		main->minfo.height++;
		tmp = tmp->next;
	}
	main->minfo.zmin[0] = ft_atoi(main->parsing->line);
	main->minfo.zmax[0] = main->minfo.zmin[0];
	// printf("Map info : \nwidth : %d\nheight : %d\nzmin : %d\n", main->minfo.width, main->minfo.height, main->minfo.zmax[0]);
}