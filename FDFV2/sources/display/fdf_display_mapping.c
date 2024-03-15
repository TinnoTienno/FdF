/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_mapping.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:46:19 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/27 16:15:13 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display_mapping(t_fdf_info_summary *summary, t_fdf_mapping ***mapping)
{
	int	i;
	int	j;

	i = -1;
	printf("+--+");
	while (++i < summary->length)
		printf("---+---+---+  +");
	printf("\n|  |");
	i = -1;
	while (++i < summary->length)
		printf(" x | y | z |  |");
	printf("\n+  +");
	i = -1;
	while (++i < summary->length)
		printf("---+---+---+  +");
	j = -1;
	while (++j < summary->width)
	{
		printf("\n|  |");
		i = -1;
		while (++i < summary->length)
			printf("%.1f|%.1f|%.1f|  |", mapping[j][i]->x, mapping[j][i]->y, mapping[j][i]->z);
		printf("\n+  +");
		i = -1;
		while (++i < summary->length)
			printf("---+---+---+  +");
		i = -1;
		printf("\n|");
		while (++i < summary->length)
			printf("               ");
		i = -1;
		printf("\n+  +");
		while (++i < summary->length)
			printf("---+---+---+  +");

	}
	printf("\n|  ");
	i = -1;
	while (++i < summary->length)
		printf("               ");
	printf("|\n+--+");
	i = -1;
	while (++i < summary->length)
		printf("---+---+---+--+");
}