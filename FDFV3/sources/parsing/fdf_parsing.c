/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:35:10 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 18:50:33 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_error(char *str)
{
	fdf_mapping_init_free(-1);
	fdf_summary_init_free(-1);
	gwf(-1);
	fd_printf(2, "%s", str);
	exit (EXIT_FAILURE);
}
static int	fdf_error_file(int size, char **tab)
{
	int	i;

	i = 0;
	if (size != 1)
		return (1);
	while (tab[0][i] == ' ' && tab[0][i] )
		i++;
	while (tab[0][i] && tab[0][i] != ' ')
	{
		if (ft_isalnum(tab[0][i] == 0) && tab[0][i] != '.' && tab[0][i] !='/')
			return (1);
		i++;
	}
	if (i < 4)
		return (1);
	if (tab[0][i - 1] != 'f' || tab[0][i - 2] != 'd' || tab[0][i - 3] != 'f' || tab[0][i - 4] != '.')
		return (1);
	return (0);
}

t_fdf_mapping	**fdf_parsing(int size, char **tab)
{
	char				*str;
	int					fd;
	t_fdf_info_summary	*summary;
	t_fdf_vertices		***mapping;

	struct t_map {
		t_fdf_info_summary info;
		t_fdf_vertices vertices;
		
	};

	if (fdf_error_file(size, tab) == 1)
		fdf_error("Error in fdf_error_file function\n");
	fd = open (tab[0], O_RDONLY);
	str = gwf(fd);
	if (!str)
		fdf_error("Error in gwf function\n");
	summary = fdf_summary_parsing(str, summary);
	mapping = fdf_mapping_init_free(0);
	mapping = fdf_mapping(str);
	free (str);
	mapping = fdf_normalization(summary, mapping);
	return (mapping);
}
