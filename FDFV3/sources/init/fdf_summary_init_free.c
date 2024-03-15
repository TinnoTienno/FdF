/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_summary_init_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:30:50 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 18:19:03 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_error(char *str)
{
	fd_printf(2, "%s", str);
	fdf_mapping_init_free(-1);
	gwf(-1);
	exit (EXIT_FAILURE);
}

t_fdf_info_summary	*fdf_summary_get()
{
	static t_fdf_info_summary	summary = {0};

	return (&summary);
}

void	fdf_summary_normalize()
{
	t_fdf_info_summary	*summary;

	summary = fdf_summary_get();	
	summary->length;
	return (summary);
}