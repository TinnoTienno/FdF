/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/26 16:53:57 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf_info_summary	*summary;
	t_fdf_mapping		***mapping;

	summary = fdf_summary_init();
	mapping = fdf_parsing(argc - 1, &argv[1], summary);
	return (0);
}