/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:19:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 22:02:35 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static int	fdf_error_file(t_main *main, char *filename)
{
	int sfile;
	int sname;

	sfile = 0;
	sname = 0;
	while (filename[sfile])
	{
		if (filename[sfile] == '/')
			sname = sfile + 1;
		sfile++;
	}
	sfile--;
	while (filename[sfile] == ' ')
		sfile--;
	if (sfile - sname <= 3)
		fdf_error(main, "Error in fdf_error_file function : filename too short\n");
	if (filename[sfile] != 'f' || filename[sfile - 1] != 'd' ||\
	filename[sfile - 2] != 'f' || filename[sfile - 3] != '.')
		fdf_error(main, "Error in fdf_error_file function : Wrong extension\n");
	return (0);
}

t_map	*fdf_mapping(char **tab, t_main *main)
{
	t_map	*map;
	
	main->arg = ft_argjoin(tab, ' ');
	if (!main->arg)
		fdf_error(main, "Error in fdf_mapping function : Malloc\n");
	if (ft_countword(main->arg, ' ') > 1)
		fdf_error(main, "Error in fdf_mapping function : Too many arguments");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		fdf_error(main, "Error in fdf_mapping function : Malloc unitialized\n");
	main->map = map;
	fdf_error_file(main, main->arg);
	fdf_parsing(main, main->arg);
	fdf_normilizing(main);
	// fdf_display_map(main);
	return (map);
}

