/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:21:25 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/10 15:30:42 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	static t_main	main = {0};

	if (argc == 1)
		return (fd_printf(2, "Error in Main function : No argument\n"), 1);
	fdf_args(&main, &argv[1]);
	fdf_mapping(&main);
	fdf_colors_init(&main);
	fdf_scale_init(&main);
	fdf_graphics(&main);
	fdf_error(&main, "");
}
