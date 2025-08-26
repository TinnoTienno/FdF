/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:29:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/08 16:23:02 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_hooks_close(t_main *main)
{
	fdf_error(main, "");
	exit (EXIT_SUCCESS);
}

int	fdf_x_cross(t_main *main)
{
	fdf_hooks_close(main);
	return (0);
}
