/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:13:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/07 13:31:52 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_flush(char *str_static, t_gnl_struct *stc, char *str)
{
	if (stc)
	{
		if (stc->str)
			free (stc->str);
		free (stc);
	}
	if (str_static)
	{
		free(str_static);
		str_static = NULL;
	}
	fd_printf(2, str);
	exit (EXIT_FAILURE);
}

void	gnl_exit(char *str_static, t_gnl_struct *stc)
{
	if (stc)
	{
		if (stc->str)
			free (stc->str);
		free (stc);
	}
	if (str_static)
	{
		free(str_static);
		str_static = NULL;
	}
}

t_gnl_struct	*gnl_stc_read(t_gnl_struct *stc, int fd, char *str_static)
{
	char	buffer[GNL_BUFFER_SIZE];
	int		reader;
	char	*strjoined;

	reader = read(fd, &buffer, GNL_BUFFER_SIZE);
	if (reader == -1)
		gnl_flush(str_static, stc, "Error\n");
	stc->read = reader;
	strjoined = malloc(stc->size + reader + 1);
	if (!strjoined)
		gnl_flush(str_static, stc, "Error\n");
	strjoined[stc->size + reader] = '\0';
	while (--reader >= 0)
	{
		strjoined[stc->size + reader] = buffer[reader];
		if (buffer[reader] == '\n')
			stc->nlpos = stc->size + reader;
	}
	reader = -1;
	while (stc->str[++reader])
		strjoined[reader] = stc->str[reader];
	stc->size = stc->read + stc->size;
	free (stc->str);
	stc->str = strjoined;
	return (stc);
}
