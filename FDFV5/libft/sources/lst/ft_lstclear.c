/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:54:19 by eschussl          #+#    #+#             */
/*   Updated: 2023/11/17 03:31:04 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!(lst) || !(del))
		return ;
	while (*lst != NULL)
	{
		while (*lst != NULL)
		{
			tmp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}
