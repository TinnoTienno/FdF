/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:30:27 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/15 21:36:21 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*##########################################################################
#                                                                           #
#                                   MACROS                                  #
#                                                                           #
 ##########################################################################*/
 
# define ESC_KEY 65307
# define S_KEY 115
# define FDF_WINDOW_HEIGHT 720
# define FDF_WINDOW_WIDTH 1080
# define FDF_WINDOW_BORDER 100

/*##########################################################################
#                                                                           #
#                                  INCLUDES                                 #
#                                                                           #
 ##########################################################################*/

#include "libft.h"
# include <mlx.h>
# include <X11/keysym.h>

/*##########################################################################
#                                                                           #
#                                 STRUCTURES                                #
#                                                                           #
 ##########################################################################*/

typedef struct s_map_info
{
	int 	width;
	int		height;
	double	zmin;
	double	zmax;
}	t_map_info;

typedef struct s_map_vertex
{
	double	x[2];
	double	y[2];
	double	z[2];
	unsigned int	colors[2];
}	t_map_vertex;

typedef struct s_map
{
	t_map_info		info;
	t_map_vertex	*vertices;
}	t_map;

typedef struct s_scale
{
	int 	bwidth;
	int		bheight;
	double	window_center_x;
	double	window_center_y;
	double	scale_x;
	double	scale_y;
	double	indexing;
}	t_scale;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_main
{
	char	*arg;
	t_map	*map;
	t_scale	scale;
	void 	*mlx;
	void	*win;
	t_data	image;
}	t_main;


/*##########################################################################
#                                                                           #
#                                 FUNCTIONS                                 #
#                                                                           #
 ##########################################################################*/
 
void	fdf_error(t_main *main, char *str);

t_map			*fdf_mapping(char **tab, t_main *main);
void fdf_parsing(t_main *main, char *filename);
t_map_info		fdf_map_info(char *str);
t_map_vertex	*fdf_vertices(t_main *main, char *str);
void fdf_normilizing(t_main *main);

void	fdf_display_map(t_main *main);

void	fdf_graphics(t_main *main);
int		fdf_graphics_keypress(int keycode, t_main *main);
void	fdf_graphics_close(t_main *main);
void	my_mlx_pixel_put(t_data *image, int x, int y, int color);
void	fdf_set_points(t_main *main);
void	fdf_draw_points(t_main *main);
int	fdf_mouse_scroll(int button, int x, int y, t_main *main);

t_scale fdf_scale_init(t_main *main);
void	fdf_scale_edit(t_main *main);

#endif