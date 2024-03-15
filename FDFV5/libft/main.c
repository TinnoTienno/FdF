/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:58:25 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/07 14:04:29 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*gnl(int fd);

int	main()
{
	int		fd;
	char	*str;
	int		i;


	i = 0;

	fd = open("les_statuts_de_l_homme.txt", O_RDONLY);
	str = gnl(fd);
	while (str)
	{
		printf("%s", str);
		free (str);
		str = gnl(fd);
	}
	free(str);
	gnl(-1);	
}