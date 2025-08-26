/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_freeparsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:01:40 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 18:36:15 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	fdf_freeparsing(t_main *main)
{
	void	*tmp;

	while (main->parsing)
	{
		tmp = main->parsing->next;
		free(main->parsing->line);
		free(main->parsing);
		main->parsing = tmp;
	}
}
