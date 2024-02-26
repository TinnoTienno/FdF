/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_summary_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:30:50 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/26 15:34:40 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_init_error(void)
{
	perror ("Error in fdf_summary_init function");
	exit (EXIT_FAILURE);
}

t_fdf_info_summary	*fdf_summary_init(void)
{
	t_fdf_info_summary	*summary;

	summary = malloc (sizeof(t_fdf_info_summary));
	if (!summary)
		fdf_init_error();
	summary->length = 0;
	summary->width = 0;
	summary->zmax = 0;
	summary->zmin = 0;
	return (summary);
}