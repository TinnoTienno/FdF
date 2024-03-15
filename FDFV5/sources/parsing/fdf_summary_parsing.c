/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_summary_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:20:10 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/06 14:18:49 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int fdf_summary_length(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '\n')
	{
		if (ft_isalnum(str[i]) && (!str[i + 1] || str[i + 1] == ' ' || str[i + 1] == '\n'))
			count++;
		i++;	
	}
	return (count);
}
static int	fdf_summary_width(char *str)
{
	int i;
	int mark;
	int	count;

	i = 0;
	count = 0;
	mark = 1;
	while (str[i])
	{
		if (mark && ft_isalnum(str[i]))
		{
			count++;
			mark = 0;
		}
		if (!mark && str[i] == '\n')
			mark = 1;
		i++;
	}
	return (count);
}
t_fdf_info fdf_summary_parsing(char *str)
{
	t_fdf_info summary;

	
	summary.length = fdf_summary_length(str);
	summary.width = fdf_summary_width(str);
	summary.zmax = ft_atoi(str);
	summary.zmin = summary.zmax;
	return (summary);
}