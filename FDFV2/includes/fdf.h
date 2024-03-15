/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:35:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/01 15:39:31 by eschussl         ###   ########.fr       */
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

typedef struct s_fdf_info_summary
{
	int			length;
	int			width;
	double		zmin;
	double		zmax;
}	t_fdf_info_summary;

typedef struct s_fdf_mapping
{
	double	x;
	double	y;
	double	z;
	int	colors;
}	t_fdf_mapping;

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

t_fdf_info_summary	*fdf_summary_init(void);

/*###########
#  PARSING	#
###########*/

t_fdf_mapping		***fdf_parsing(int size, char **tab, t_fdf_info_summary *summary);
t_fdf_mapping		***fdf_mapping(char *str, t_fdf_info_summary *summary, t_fdf_mapping ***mapping);
t_fdf_mapping		**fdf_mapping_line(char *str, t_fdf_info_summary *summary, int *i, int y);
t_fdf_info_summary	*fdf_summary_parsing(char *str, t_fdf_info_summary *summary);
t_fdf_mapping		***fdf_normalization(t_fdf_info_summary *summary, t_fdf_mapping ***mapping);

/*###########
#	FREE	#
###########*/

void	fdf_free_mapping(t_fdf_mapping ***mapping, t_fdf_info_summary *summary);

/*###########
#  DISPLAY	#
###########*/

void	fdf_display_mapping(t_fdf_info_summary *summary, t_fdf_mapping ***mapping);
void	fdf_display_summary(t_fdf_info_summary *summary);

/*###########
# GRAPHICS	#
###########*/

void	fdf_graphics_display(t_fdf_info_summary *summary, t_fdf_mapping ***mapping);
void	fdf_graphics_close(t_vars *vars);
int	fdf_graphics_keypress(int keycode, t_vars *vars);

#endif