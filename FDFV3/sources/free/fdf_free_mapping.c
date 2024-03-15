/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_mapping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:29:12 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 16:41:31 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_free_mapping(t_fdf_mapping ***mapping, t_fdf_info_summary *summary)
{
	int i;
	int j;

	if (!mapping)
		return ;
	i = 0;
	while (i < summary->width)
	{
		j = 0;
		while (j < summary->length)
		{
			free (mapping[i][j]);
			j++;
		}
		free (mapping[i]);
		i++;
	}
	free (mapping);
}