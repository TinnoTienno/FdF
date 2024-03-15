/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_summary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:48:22 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 21:05:59 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display_summary(t_fdf_info summary)
{
	ft_printf("Parsing info :\n");
	ft_printf("length : %d\n", summary.length);
	ft_printf("width : %d\n", summary.width);
	printf("zmin : %f\n", summary.zmin);
	printf("zmax : %f\n", summary.zmax);
}