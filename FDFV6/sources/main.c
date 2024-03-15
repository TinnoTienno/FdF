/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:08 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 21:51:07 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_main	main;


	if (argc == 1)
		return (fd_printf(2, "Error in Main function : No arguments\n"), 1);
	main.map = fdf_mapping(&argv[1], &main);
	main.scale = fdf_scale_init(&main);
	fdf_graphics(&main);
	fdf_error(&main, "");
}