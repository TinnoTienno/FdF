/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:16:20 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/26 17:54:26 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_error_mapping(char *str, t_fdf_info_summary *summary, t_fdf_mapping ***mapping)
{
	int	i;
	int j;

	i = 0;
	if (str)
		free (str);
	if (summary)
		free (summary);
	if (mapping)
	{
		while (mapping[i])
		{
			j = 0;
			while (mapping[i][j])
			{
				free (mapping[i][j]);
				j++;
			}
			free (mapping[i]);
			i++;
		}
		free (mapping);
	}
	fd_printf(2, "Error in fdf_mapping fucntion\n");
}

t_fdf_mapping	***fdf_mapping(char *str, t_fdf_info_summary *summary, t_fdf_mapping ***mapping)
{
	int y;
	int	i;

	y = 0;
	i = 0;
	while (y < summary->width)
	{
		mapping[y] = fdf_mapping_line(str, summary, &i, y);
		if (!mapping[y])
			fdf_error_mapping(str, summary, mapping);
		y++;
	}
	return (mapping);
}