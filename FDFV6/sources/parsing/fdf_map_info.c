/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:25:41 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/13 14:53:39 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_info_height(char *str)
{
	return (ft_countword(str, '\n'));
}

static int	fdf_info_width(char **tab)
{
	int	res;
	int i;

	res = ft_countword(tab[0], ' ');
	i = 0;
	while (tab[i])
	{
		if (ft_countword(tab[i], ' ') != res)
			return (-1);
		i++;
	}
	return (res);
}

t_map_info	fdf_map_info(char *str)
{
	t_map_info info;
	char **tab;
	
	tab = ft_split(str, '\n');
	info.width = fdf_info_width(tab);
	info.height = fdf_info_height(str);
	info.zmax = ft_atoi(str);
	info.zmin = info.zmax;
	ft_freectab(tab);
	return (info);
}