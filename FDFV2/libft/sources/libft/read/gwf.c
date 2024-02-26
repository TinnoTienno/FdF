/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gwf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:56:01 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/26 22:56:58 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gwf_strjoin(char *heap, char *stack)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	if (!heap)
	{
		res = malloc (ft_strlen(stack) + 1);
		while (stack[++i])
			res[i] = stack[i];
		res[i] = 0;
		return (res);
	}
	res = malloc (ft_strlen(stack) + ft_strlen(heap) + 1);
	while (heap[++i])
		res[i] = heap[i];
	j = -1;
	while (stack[++j])
		res[i + j] = stack[j];
	res[i + j] = 0;
	free (heap);
	return (res);
}

char	*gwf(int fd)
{
	char	*res;
	char	buffer[GWF_BUFFER_SIZE + 1];
	int		reader;

	reader = read(fd, &buffer, GWF_BUFFER_SIZE);
	buffer[GWF_BUFFER_SIZE] = 0;
	if (reader <= 0)
		return (fd_printf(2, "Error : Nothing to read in function gwf\n"), NULL);
	res = malloc (sizeof(reader + 1));
	if (!res)
		return (NULL);
	res[0] = 0;
	while (reader == GWF_BUFFER_SIZE)
	{
		printf("res : |\n%s|\n", res);
		printf("buffer : |%s|\n", buffer);
		res = gwf_strjoin(res, buffer);
		if (!res)
			return (NULL);
		reader = read(fd, &buffer, GWF_BUFFER_SIZE);
	}
	res = gwf_strjoin(res, buffer);
	return (res);
}
