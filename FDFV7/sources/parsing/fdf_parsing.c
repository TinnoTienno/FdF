/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:50:58 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/18 17:07:06 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static t_parsing *fdf_new_node(t_main *main, int fd, t_parsing *previous)
{
	t_parsing *new;

	new = ft_calloc(sizeof(t_parsing), 1);
	if (!new)
		gnl(-1);
	if (!new)
		fdf_error(main, "Error in fdf_new_node function : Malloc\n");
	new->line = gnl(fd);
	while (new->line && new->line[0] == '\n')
	{
		free (new->line);
		new->line = gnl(fd);
	}
	if (new->line && new->line[ft_strlen(new->line) - 1] == '\n')
		new->line[ft_strlen(new->line) - 1] = 0;
	new->next = NULL;
	previous->next = new;
	return (new);
}

static void	fdf_list_build(t_main *main, int fd)
{
	t_parsing	*new;
	t_parsing	*tmp;
	
	main->list->line = gnl(fd);
	if (!main->list->line)
		fdf_error(main, "Error in fdf_list_build function : Empty file\n");
	while (main->list->line && main->list->line[0] == '\n')
	{
		free (main->list->line);
		main->list->line = gnl(fd);
		if (!main->list->line)
			fdf_error(main, "Error in fdf_list_build function : Empty file\n");
	}
	if (main->list->line[ft_strlen(main->list->line) - 1] == '\n')
		main->list->line[ft_strlen(main->list->line) - 1] = 0;
	main->list->next = NULL;
	tmp = main->list;
	while (tmp->line)
	{
		new = fdf_new_node(main, fd, tmp);
		tmp = new;
	}
}

void	fdf_parsing(t_main *main)
{
	int	fd;
	
	printf("%s\n", main->file_info.filename);
	fd = open(main->file_info.filename, O_RDONLY);
	if (fd == -1)
	{
		close (fd);
		fdf_error(main, "Error in FDF_PARSING function : Could not open file\n");
	}
	main->list = ft_calloc(sizeof(t_parsing), 1);
	if (!main->list)
		fdf_error(main, "Error in FDF_PARSING function : Malloc\n");
	fdf_list_build(main, fd);
	close (fd);
	// fdf_display_list(main);
}
