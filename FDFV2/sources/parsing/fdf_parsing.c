/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:35:10 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/28 18:22:51 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_parsing_error(char *str2, t_fdf_info_summary *summary, char *str)
{
	free (summary);
	if (str)
		free (str2);
	fd_printf(2, str);
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

t_fdf_mapping	***fdf_parsing(int size, char **tab, t_fdf_info_summary *summary)
{
	t_fdf_mapping	***mapping;
	char			*str;
	int				fd;

	if (fdf_error_file(size, tab) == 1)
		fdf_parsing_error(NULL, summary, "Error in fdf_error_file function\n");
	fd = open (tab[0], O_RDONLY);
	str = gwf(fd);
	if (!str)
		fdf_parsing_error(NULL, summary, "Error in gwf function\n");
	summary = fdf_summary_parsing(str, summary);
	mapping = malloc (sizeof(t_fdf_mapping**) * summary->width);
	if (!mapping)
		fdf_parsing_error(str, summary, "Error in fdf_mapping_function\n");
	mapping = fdf_mapping(str, summary, mapping);
	free (str);
	mapping = fdf_normalization(summary, mapping);
	return (mapping);
}
