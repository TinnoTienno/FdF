/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/10 15:36:08 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars		*vars;
	
	vars = ft_calloc(1, sizeof(t_vars));
	vars->map = fdf_mapping(argc - 1, &argv[1], vars);
	fdf_init_status(vars);
	fdf_graphics(vars, argv[1]);
	return (0);
}