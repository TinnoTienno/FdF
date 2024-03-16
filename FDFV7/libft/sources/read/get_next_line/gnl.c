/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:16:04 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 23:08:55 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl_struct	*gnl_stc_static(char *str_static)
{
	t_gnl_struct	*stc;
	int				i;

	stc = malloc(sizeof(t_gnl_struct));
	if (!stc)
		gnl_flush(str_static, NULL, "Error\n");
	stc->str = malloc(GNL_BUFFER_SIZE + 1);
	if (!stc->str)
		gnl_flush(str_static, stc, "Error\n");
	i = 0;
	stc->nlpos = -1;
	while (str_static[i])
	{
		stc->str[i] = str_static[i];
		if (stc->nlpos == -1 && stc->str[i] == '\n')
			stc->nlpos = i;
		i++;
	}
	stc->read = GNL_BUFFER_SIZE;
	stc->size = i;
	stc->str[i] = '\0';
	return (stc);
}

t_gnl_struct	*gnl_stc_no_static(int fd)
{
	t_gnl_struct	*stc;
	int				reader;
	char			buffer[GNL_BUFFER_SIZE];

	stc = malloc(sizeof(t_gnl_struct));
	if (!stc)
		gnl_flush(NULL, NULL, "Error\n");
	stc->str = malloc (GNL_BUFFER_SIZE + 1);
	if (!stc->str)
		gnl_flush(NULL, stc, "Error\n");
	reader = read(fd, &buffer, GNL_BUFFER_SIZE);
	if (reader == -1)
		gnl_flush(NULL, stc, "Error\n");
	stc->str[reader] = '\0';
	stc->size = reader;
	stc->nlpos = -1;
	stc->read = reader;
	while (--reader >= 0)
	{
		stc->str[reader] = buffer[reader];
		if (stc->str[reader] == '\n')
			stc->nlpos = reader;
	}
	return (stc);
}

char	*gnl_str_return(t_gnl_struct *stc, char *str_static)
{
	char	*str_return;
	int		i;

	if (stc->size == 0)
		return (NULL);
	if (stc->nlpos != -1)
		str_return = malloc (stc->nlpos + 2);
	else
		str_return = malloc (stc->size + 1);
	if (!str_return)
		gnl_flush(str_static, stc, "Error\n");
	i = -1;
	if (stc->nlpos != -1)
	{
		while (++i <= stc->nlpos)
			str_return[i] = stc->str[i];
	}
	else
	{
		while (stc->str[++i])
			str_return[i] = stc->str[i];
	}
	str_return[i] = '\0';
	return (str_return);
}

char	*gnl_str_static(char *str_static, t_gnl_struct *stc)
{
	int	i;
	int	j;

	if (stc->nlpos == -1 || stc->nlpos == stc->size - 1)
		return (gnl_exit(str_static, stc), NULL);
	free (str_static);
	str_static = malloc (GNL_BUFFER_SIZE + 1);
	if (!str_static)
		gnl_flush(str_static, stc, "Error\n");
	i = stc->nlpos + 1;
	j = 0;
	while (stc->str[i])
		str_static[j++] = stc->str[i++];
	free(stc->str);
	free(stc);
	str_static[j] = '\0';
	return (str_static);
}

char	*gnl(int fd)
{
	static char		*str_static = NULL;
	char			*str_return;
	t_gnl_struct	*stc;

	if (GNL_BUFFER_SIZE < 1 || fd < GNL_ERROR || (fd > GNL_ERROR && fd < 0))
		gnl(GNL_ERROR);
	if (fd == GNL_ERROR)
		gnl_flush(str_static, NULL, "");
	if (str_static)
		stc = gnl_stc_static(str_static);
	else
		stc = gnl_stc_no_static(fd);
	while (stc->nlpos == -1 && stc->read == GNL_BUFFER_SIZE)
		stc = gnl_stc_read(stc, fd, str_static);
	str_return = gnl_str_return(stc, str_static);
	str_static = gnl_str_static(str_static, stc);
	return (str_return);
}
