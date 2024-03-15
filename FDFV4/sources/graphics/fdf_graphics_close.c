/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphics_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:37:19 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/07 17:28:38 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_graphics_close(t_vars *vars)
{
	fdf_error(vars, "");
	mlx_loop_end(vars->mlx);
	exit (EXIT_SUCCESS);
	return ;
}
