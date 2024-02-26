/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:35:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/26 20:36:12 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_fdf_info_summary
{
	int		length;
	int		width;
	int		zmin;
	int		zmax;
}	t_fdf_info_summary;

typedef struct s_fdf_mapping
{
	double	x;
	double	y;
	double	z;
	double	colors;
}	t_fdf_mapping;

/*###########
#	INIT	#
###########*/

t_fdf_info_summary	*fdf_summary_init(void);

/*###########
#  PARSING	#
###########*/

t_fdf_mapping		***fdf_parsing(int size, char **tab, t_fdf_info_summary *summary);
t_fdf_mapping		***fdf_mapping(char *str, t_fdf_info_summary *summary, t_fdf_mapping ***mapping);
t_fdf_mapping		**fdf_mapping_line(char *str, t_fdf_info_summary *summary, int *i, int y);
t_fdf_info_summary	*fdf_summary_parsing(char *str, t_fdf_info_summary *summary);

#endif