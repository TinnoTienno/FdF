/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 18:32:31 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf_info_summary	*summary;
	t_fdf_mapping		**mapping;
	
	(void)	argc;
	(void)	argv;
	summary = fdf_summary_init_free(0);
	mapping = fdf_parsing(argc - 1, &argv[1]);
	fdf_summary_init_free(-1);
	// fdf_mapping_init_free(-1);
	return (0);
}