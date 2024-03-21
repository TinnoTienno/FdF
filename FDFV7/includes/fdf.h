/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:30:27 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/21 15:50:01 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*##########################################################################
#                                                                           #
#                                   MACROS                                  #
#                                                                           #
 ##########################################################################*/
 
# define DEFAULT_WINDOW_HEIGHT 720
# define DEFAULT_WINDOW_WIDTH 1080
# define DEFAULT_WINDOW_BORDER 200

/*##########################################################################
#                                                                           #
#                                  INCLUDES                                 #
#                                                                           #
 ##########################################################################*/

# include "libft.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <math.h>

/*##########################################################################
#                                                                           #
#                                 STRUCTURES                                #
#                                                                           #
 ##########################################################################*/

typedef	struct s_minfo
{
	int		width;
	int		height;
	int		total;
	int		zmin;
	int		zmax;
}	t_minfo;

typedef	struct s_vertex
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_vertex;

typedef struct s_map
{
	t_minfo		info;
	t_vertex	**vertices;
}	t_map;

typedef struct	s_finfo
{
	char	*args;
	char	*filename;
	int		window_width;
	int		window_height;
	int		window_border;
}	t_finfo;

typedef struct	t_parsing
{
	void	*next;
	char	*line;
}	t_parsing;

typedef struct s_color
{
	int color_deepsea;
	int color_shallowsea;
	int color_beach;
	int	color_greenland;
	int	color_moutain;
	int color_top;
	double	bottom_level;
	double	shallow_sea_level;
	double	beach_level;
	double	greenland_level;
	double	moutain_level;
	double	top_level;
}	t_color;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		center_x;
	int		center_y;
}			t_data;

typedef struct s_display
{
	int		x;
	int		y;
	int		color1;
	int		color2;
}	t_display;

typedef struct s_event
{
	int	color_mode;
	int	view_mode;
	int	line_mode;
}	t_event;

typedef struct s_main
{
	t_finfo		file_info;
	t_parsing	*list;
	t_map		map;
	t_color		colors;
	void		*mlx;
	void		*win;
	t_data		image;
	t_event		event;
	t_display	**display;
}	t_main;


/*##########################################################################
#                                                                           #
#                                 FUNCTIONS                                 #
#                                                                           #
 ##########################################################################*/
 
void	fdf_args(t_main *main, char **args);
void	fdf_mapping(t_main *main);
void	fdf_parsing(t_main *main);
void	fdf_map_info(t_main *main);
void	fdf_vertices(t_main *main);
void	fdf_normilizing(t_main *main);
void	fdf_colors_set(t_main *main);

void	fdf_error(t_main *main, char *error_message);

void	fdf_display_list(t_main *main);
void	fdf_display_map(t_main *main, char c);
void	fdf_display_vertex(t_main *main, int y, int x);
void	fdf_display_display(t_main *main);

void	fdf_main_init(t_main *main);
void	fdf_colors_init(t_main *main);
void	fdf_display_init(t_main *main);

void	fdf_graphics(t_main *main);
void	fdf_image_init(t_main *main);
void	fdf_graphics_close(t_main *main);
int		fdf_graphics_keypress(int keycode, t_main *main);
void	fdf_draw_points(t_main *main);
void	my_mlx_pixel_put(t_main *main, int x, int y, int color);
void	fdf_clean_win(t_main *main);
int		fdf_push_loop(t_main *main);
int		fdf_offsetx(t_main *main, double x);
int		fdf_offsety(t_main *main, double y);
void	fdf_move(t_main *main, int keycode);

void	fdf_event(t_main *main, int c);
void	my_mlx_pixel_put(t_main *main, int x, int y, int color);

int		fdf_color_shift(double index, int color0, int color1);
int		fdf_color2_vertex(double z, t_main *main);
void	fdf_color_parsing(t_main *main);

#endif