/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:35:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/10 13:15:16 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
#include <math.h>
#include <mlx.h>

# define ESC_KEY 65307

typedef struct s_fdf_info
{
	int			length;
	int			width;
	double		zmin;
	double		zmax;
}	t_fdf_info;

typedef struct s_fdf_vertex
{
	double	x;
	double	y;
	double	z;
	int		colors;
}	t_fdf_vertex;

typedef struct s_fdf_map
{
	t_fdf_vertex	*vertices;
	t_fdf_info 		info;
}	t_fdf_map;

typedef struct	s_graphics_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_graphics_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

/*###########
#	INIT	#
###########*/



/*###########
#  PARSING	#
###########*/

t_fdf_map	*fdf_mapping(int size, char **tab);
t_fdf_map *fdf_parsing(t_fdf_map *map, char **tab);
t_fdf_info fdf_summary_parsing(char *str);
t_fdf_map *fdf_vertices(t_fdf_map *map, char *str);

/*###########
#	FREE	#
###########*/

void	fdf_error(t_fdf_map *map, t_vars *vars, char *print);

/*###########
#  DISPLAY	#
###########*/

void	fdf_display_summary(t_fdf_info summary);
void	fdf_display_mapping(t_fdf_map *map);

/*###########
# GRAPHICS	#
###########*/



#endif