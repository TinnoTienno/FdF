/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:31:50 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/25 19:47:49 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int fdf_errorfd(int size, char *name)
{
	int		fd;
	char	*buffer;
	if (size != 1)
	{
		exit(EXIT_FAILURE);
		fprintf(stderr, "error\n");
	}
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror("Error in function errorfd function");
		close (fd);
		exit(EXIT_FAILURE);
	}
	if (read(fd, buffer, 0) == -1)
	{
		perror("Error in function errorfd function");
		close (fd);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
char	*fdf_parsing(int fd)
{
	char *res;

	res = gwf(fd);
	if (!res)
	{
		perror("Error in function fdf_parsing function ");
		close (fd);
		exit (EXIT_FAILURE);
	}
	return (res);
}

int	**fdf_tabline(char **tabchar, int l, int **tabint)
{
	char	**str;
	int		j;
	
	str = ft_split(tabchar[l], ' ');
	if (!str)
	{
		fdf_freetabchar(tabchar);
		fdf_freetabint(tabint, l);
	}
	j = 0;
	tabint[l] = malloc (ft_tablen(str));
	if (!tabint[l])
	{
		fdf_freetabchar(str);
		fdf_freetabchar(tabchar);
		fdf_freetabint(tabint, l);
	}
	while (str[j])
	{
		fdf_errorparsing(str[j]);
		tabint[l][j] = ft_atoi(str[j]);
		j++;	
	}
	return (tabint);
}
int	**fdf_tabbuild(char *str, t_fdf_tabint **tabint)
{
	char **tabchar;
	int	i;
	int	l;
	
	tabchar = ft_split(str, '\n');
	if (!tabchar)
		exit (EXIT_FAILURE);
	while (tabchar[l])
	{
		tabint[l] = fdf_tabline(tabchar, l, tabint);
		l++;
	}
	tabint[l] = NULL;
	ft_freetabchar(tabchar);
	return (tabint);
}

int	fdf_countline(char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

t_fdf_tabint	**fdf_tab(int fd)
{
	char			*str;
	t_fdf_tabint	**tabint;

	str = fdf_parsing(fd);
	tabint = malloc (sizeof(t_fdf_tabint *) * (fdf_countline(str) + 1));
	if (!tabint)
	{
		free (str);
		perror("Error in function fdf_tabbuild function ");
		exit (EXIT_FAILURE);
	}
	tabint = fdf_tabintinit(tabint);
	tabint = fdf_tabbuild(str, tabint);
}
int	main(int argc, char **argv)
{
	int fd;
	t_fdf_tabint **tabint;
	
	fd = fdf_errorfd(argc - 1, argv[1]);
	tabint = fdf_tab(fd);
	
}