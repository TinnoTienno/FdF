/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping_init_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:33:01 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 18:29:55 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void	fdf_error(char *str)
{
	fd_printf(2, "%s", str);
	fdf_summary_init_free(-1);
	gwf(-1);
	exit (EXIT_FAILURE);
}

static void fdf_free_mapping(t_fdf_mapping ***mapping)
{
	t_fdf_info_summary	*summary;
	int	i;
	int	j;

	summary = fdf_summary_init_free(0);
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

t_fdf_mapping	**fdf_mapping_init_free(int instruction)
{
	static t_fdf_mapping	**mapping = NULL;
	
	if (instruction == -1 && mapping)
		return (ft_free_mapping(mapping), NULL);
	else if (instruction == -1)
		return (NULL);
	if (!mapping)
		mapping = malloc (sizeof(t_fdf_mapping*) * fdf_summary_init_free(0)->width);
	if (!mapping)
		return (fdf_error("Error in fdf_mapping_init_free function\n"), NULL);
	return (mapping);
}