/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_normalization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:18:49 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/27 17:33:23 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_fdf_mapping	*fdf_norm_point_xy(t_fdf_info_summary *summary, t_fdf_mapping *mapping)
{
	double	xmid;
	double	ymid;
	
	if (summary->width % 2 == 1)
		xmid = summary->width / 2;
	else
		xmid = summary->width / 2 - 1;
	if (summary->length % 2 == 1)
		ymid = summary->length / 2;
	else
		ymid = summary->length / 2 - 1;
	mapping->x = mapping->x - xmid;
	mapping->y = mapping->y - ymid;
	return (mapping);
}

static t_fdf_mapping	*fdf_norm_point_z(t_fdf_info_summary *summary, t_fdf_mapping *mapping)
{
	mapping->z = mapping->z - summary->zmin;
	return (mapping);
}
t_fdf_mapping	***fdf_normalization(t_fdf_info_summary *summary, t_fdf_mapping ***mapping)
{
	int	i;
	int	j;

	i = -1;
	while (++i < summary->width)
	{
		j = -1;
		while (++j < summary->length)
		{
			fdf_norm_point_xy(summary, mapping[i][j]);
			fdf_norm_point_z(summary, mapping[i][j]);
		}
	}
	return (mapping);
}