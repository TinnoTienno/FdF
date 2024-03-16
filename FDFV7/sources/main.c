/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:08 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 23:15:27 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc == 1)
		return (fd_printf(2, "Error in Main function : No argument\n"), 1);
	fdf_main_init(&main);
	fdf_args(&main, &argv[1]);
	fdf_mapping(&main);
	fdf_error(&main, "end\n");
}