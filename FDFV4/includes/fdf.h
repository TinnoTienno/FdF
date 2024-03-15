/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:35:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/13 17:11:53 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <math.h>
# include <mlx.h>

# define ESC_KEY 65307
# define S_KEY 115
# define FDF_WINDOW_HEIGHT 720
# define FDF_WINDOW_WIDTH 1080
# define FDF_WINDOW_BORDER 20

/// @brief ////////////////////////////////////////////

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
	int	colors;
}	t_fdf_vertex;

typedef struct s_fdf_map
{
	t_fdf_vertex	*vertices;
	t_fdf_info 		info;
}	t_fdf_map;

/////////////////////////////////////////////////////

typedef struct	s_graphics_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_graphics_data;


typedef struct	s_scale {
	int			on;
	t_point		p0;
	t_point		pc;
	int 		width;
	int			heigth;
	int			xone;
	int			yone;
}				t_scale;


typedef struct	s_point {
	int	x;
	int y;
}				t_point;

typedef struct	s_polynome {
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_point	p4;
	int		heigth;
	int		width;
}				t_polynome;

typedef struct	s_status {
	int s;
}				t_status;

/////////////////////////////////////////////////////////////

typedef struct	s_vars {
	void			*mlx;
	void			*win;
	t_graphics_data img;
	t_fdf_map		*map;
	t_scale			scale;
	t_status		status;
}				t_vars;

/*###########
#	INIT	#
###########*/

/*###########
#  PARSING	#
###########*/

t_fdf_map	*fdf_mapping(int size, char **tab, t_vars *vars);
t_fdf_map *fdf_parsing(t_fdf_map *map, char **tab, t_vars *vars);
t_fdf_info fdf_summary_parsing(char *str);
t_fdf_map *fdf_vertices(t_fdf_map *map, char *str);

/*###########
#	FREE	#
###########*/

void	fdf_error(t_vars *vars, char *print);

/*###########
#  DISPLAY	#
###########*/

void	fdf_display_summary(t_fdf_info summary);
void	fdf_display_mapping(t_fdf_map *map);

/*###########
# GRAPHICS	#
###########*/

void	fdf_graphics(t_vars *vars, char *str);
int	fdf_graphics_keypress(int keycode, t_vars *vars);
void	fdf_graphics_close(t_vars *vars);
void draw_line(t_point p0, t_point p1, t_graphics_data *vars);
void	fdf_graphics_instructions(t_vars *vars);

void	my_mlx_pixel_put(t_graphics_data *data, int x, int y, int color);

#endif