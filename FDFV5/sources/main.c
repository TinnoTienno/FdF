/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:26:00 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/06 14:07:44 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	
	t_fdf_map		*map;
	
	map = fdf_mapping(argc - 1, &argv[1]);
	fdf_error(map, NULL, "");
	return (0);
}