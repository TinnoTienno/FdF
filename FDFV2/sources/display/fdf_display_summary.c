/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_summary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:10:33 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/27 17:14:16 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display_summary(t_fdf_info_summary *summary)
{
	printf("summary : \n");
	printf("length : %d\n", summary->length);
	printf("width : %d\n", summary->width);
	printf("zmin : %f\n", summary->zmin);
	printf("zmax : %f\n", summary->zmax);
}