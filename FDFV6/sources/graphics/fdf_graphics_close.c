/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:37:19 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 20:18:57 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_graphics_close(t_main *main)
{
	fdf_error(main, "");
	// mlx_loop_end(main->mlx);
	exit (EXIT_SUCCESS);
	return ;
}
