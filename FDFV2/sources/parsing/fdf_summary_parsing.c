/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_summary_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:47:28 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/26 22:34:11 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_info_summary	*fdf_summary_parsing(char *str, t_fdf_info_summary *summary)
{
	int i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	summary->length = count;
	count = 1;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	summary->width = count;
	return (summary);
}