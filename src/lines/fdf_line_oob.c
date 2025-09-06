/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line_oob.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:05:46 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/10 15:00:14 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_point_oob(t_main *main, t_vertex *vertex)
{
	if (vertex->val[1][0] < DEFAULT_WINDOW_BORDER)
		return (1);
	if (vertex->val[1][0] > main->finfo.w_width - DEFAULT_WINDOW_BORDER)
		return (3);
	if (vertex->val[1][1] < 0 + DEFAULT_WINDOW_BORDER)
		return (2);
	if (vertex->val[1][1] > main->finfo.w_height - DEFAULT_WINDOW_BORDER)
		return (4);
	return (0);
}

int	fdf_line_oob(t_main *main, t_vertex *v1, t_vertex *v2)
{
	int	oob1;
	int	oob2;

	oob1 = fdf_point_oob(main, v1);
	oob2 = fdf_point_oob(main, v2);
	if (oob1 == 0 || oob2 == 0)
		return (0);
	if (oob1 == 1)
		return (1);
	if (oob1 == 2)
		return (2);
	if (oob1 == 3)
		return (3);
	if (oob1 == 4)
		return (4);
	return (0);
}
