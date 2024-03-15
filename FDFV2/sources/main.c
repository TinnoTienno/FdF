/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/28 18:19:17 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf_info_summary	*summary;
	t_fdf_mapping		***mapping;

	summary = fdf_summary_init();
	mapping = fdf_parsing(argc - 1, &argv[1], summary);
	fdf_graphics_display(summary, mapping);
	fdf_free_mapping(mapping, summary);
	free (summary);
	return (0);
}