/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_summary_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:47:28 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/27 17:40:11 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_info_summary	*fdf_summary_parsing(char *str, t_fdf_info_summary *summary)
{
	int i;
	int mark;
	int	count;
	
	i = 0;
	count = 0;
	while (str[i] && str[i] != '\n')
	{
		if (ft_isalnum(str[i]) && (!str[i + 1] || str[i + 1] == ' ' || str[i + 1] == '\n'))
			count++;
		i++;
	}
	summary->length = count;
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
	summary->width = count;
	return (summary);
}
