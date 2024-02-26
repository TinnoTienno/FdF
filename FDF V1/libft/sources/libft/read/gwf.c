/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gwf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:56:01 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/25 18:11:48 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gwf(int fd)
{
	char	*res;
	char	*buffer;
	int		reader;

	reader = read(fd, &buffer, GWF_BUFFER_SIZE);
	if (reader == 0)
		return (fd_printf(2, "Error : Nothing to read in function gwf\n"), NULL);
	res = malloc (sizeof(reader + 1));
	if (!res)
		return (NULL);
	while (reader)
	{
		res = ft_strjoin(res, buffer);
		if (!res)
			return (NULL);
		reader = read(fd, buffer, GWF_BUFFER_SIZE);
	}
	return (res);
}