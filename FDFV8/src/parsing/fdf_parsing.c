/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:21:23 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/02 14:51:06 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*For explanation, I chose to use a list to keep each line in so I could more easily 
	study the number of lines \ columns before the final map*/
	
#include "fdf.h"
static t_parsing	*fdf_new_node(t_main *main, int fd, t_parsing *previous)
{
	t_parsing	*new;

	new = ft_calloc(sizeof(t_parsing), 1);
	if (!new)
		gnl(-1);
	if (!new)
		fdf_error(main, "Error in fdf_new_node_function : Malloc\n");
	new->line = gnl(fd);
	while (new->line && new->line[0] == '\n')
	{
		free(new->line);
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
	t_parsing	*tmp;
	t_parsing	*new;
	
	main->parsing->line = gnl(fd);
	if (!main->parsing->line)
		fdf_error(main, "Error in fdf_list_build function : Empty file\n");
	while (main->parsing->line && main->parsing->line[0] == '\n')
	{
		free(main->parsing->line);
		main->parsing->line = gnl(fd);
		if (!main->parsing->line)
		{
			free (main->parsing);
			fdf_error(main, "Error in fdf_list_build function : Empty file\n");
		}
	}
	if (main->parsing->line[ft_strlen(main->parsing->line) - 1] == '\n')
		main->parsing->line[ft_strlen(main->parsing->line) - 1] = 0;
	main->parsing->next = NULL;
	tmp = main->parsing;
	while (tmp->line)
	{
		new = fdf_new_node(main, fd, tmp);
		tmp = new;
	}
}
void	fdf_parsing(t_main *main)
{
	int fd;
	fd = open(main->finfo.filename, O_RDONLY);
	if (fd == -1)
	{
		close (fd);
		fdf_error(main, "Error in FDF_PARSING function : Could not open file\n");
	}
	main->parsing = ft_calloc(sizeof(t_parsing), 1);
	if (!main->parsing)
		fdf_error(main, "Error in fdf_list_build function : Malloc\n");
	fdf_list_build(main, fd);
	close (fd);
	// fdf_print_list(main->parsing);
}