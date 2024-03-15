/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:16:20 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 18:02:14 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_error_mapping(char *str, t_fdf_info_summary *summary, t_fdf_mapping **mapping)
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
			free (mapping[i]);
			i++;
		}
		free (mapping);
	}
	fd_printf(2, "Error in fdf_mapping function\n");
}

t_fdf_mapping	**fdf_mapping(char *str)
{
	int 				y;
	int					i;
	t_fdf_mapping		**mapping;

	mapping = fdf_mapping_init_free(0);
	y = 0;
	i = 0;
	while (y < fdf_summary_init_free(0)->width)
	{
		mapping[y] = fdf_mapping_line(str, &i, y);
		if (!mapping[y])
			fdf_error_mapping(str, mapping);
		y++;
	}
	return (mapping);
}

