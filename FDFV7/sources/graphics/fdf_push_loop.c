/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_push_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:48:01 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/25 15:40:43 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_push_loop(t_main *main)
{
	fdf_clean_win(main);
	fdf_isometric(main);
	fdf_draw_points(main);
	// fdf_draw_lines(main);
	return (0);
}