/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:09:22 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 19:14:03 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display_list(t_main *main)
{
	t_parsing *tmp;
	if (!main->list)
		return (fd_printf(2, "No list to printf\n"), (void) 1);
	tmp = main->list;
	while (tmp->next)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
}