/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:30:27 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/28 21:51:24 by eschussl         ###   ########.fr       */
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
# define DEFAULT_WINDOW_BORDER 30
# define _USE_MATH_DEFINES
# define VERTEX(x, y) (main->map.vertices[(y)][(x)])
# define VALUE(vertex, i, j) ((vertex).values[(i)][(j)])
# define M_PI 3.14159265358979323846

/*##########################################################################
#                                                                           #
#                                  INCLUDES                                 #
#                                                                           #
 ##########################################################################*/

# include "libft.h"
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>

/*##########################################################################
#                                                                           #
#                                 STRUCTURES                                #
#                                                                           #
 ##########################################################################*/

typedef struct s_minfo
{
	int			width;
	int			height;
	int			total;
	int			zmin;
	int			zmax;
}				t_minfo;

typedef struct s_vertex
{
	double		values[2][3];
	int			color;
	int			colormod;
}				t_vertex;

typedef struct s_map
{
	t_minfo		info;
	t_vertex	**vertices;
}				t_map;

typedef struct s_finfo
{
	char		*args;
	char		*filename;
	int			window_width;
	int			window_height;
	int			window_border;
}				t_finfo;

typedef struct t_parsing
{
	void		*next;
	char		*line;
}				t_parsing;

typedef struct s_color
{
	int			color_deepsea;
	int			color_shallowsea;
	int			color_beach;
	int			color_greenland;
	int			color_moutain;
	int			color_top;
	double		bottom_level;
	double		shallow_sea_level;
	double		beach_level;
	double		greenland_level;
	double		moutain_level;
	double		top_level;
}				t_color;

typedef struct s_data
{
	void		*img;
	char		*addr;
	char		*zaddr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			center_x;
	int			center_y;
}				t_data;

typedef struct s_display
{
	int			x;
	int			y;
	int			color1;
	int			color2;
}				t_display;

typedef struct s_event
{
	int			color_mode;
	int			view_mode;
	int			line_mode;
	double		x_angle;
	double		z_angle;
	double		scaling;
	double		z_mod;
}				t_event;

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
	int			**image_z;
}				t_main;

typedef struct	s_lines
{
	int dx;
    int dy;
	int err;
    int sx;
	int	sy;
    int e2;
}	t_lines;

/*##########################################################################
#                                                                           #
#                                 FUNCTIONS                                 #
#                                                                           #
 ##########################################################################*/

void			fdf_args(t_main *main, char **args);
void			fdf_mapping(t_main *main);
void			fdf_parsing(t_main *main);
void			fdf_map_info(t_main *main);
void			fdf_vertices(t_main *main);
void			fdf_normilizing(t_main *main);
void			fdf_colors_set(t_main *main);

void			fdf_error(t_main *main, char *error_message);

void			fdf_display_list(t_main *main);
void			fdf_display_map(t_main *main, char c);
void			fdf_display_vertex(t_main *main, int y, int x);
void			fdf_display_display(t_main *main);

void			fdf_main_init(t_main *main);
void			fdf_colors_init(t_main *main);
void			fdf_display_init(t_main *main);
void			fdf_scale_init(t_main *main);
void			fdf_image_z_init(t_main *main);
void			fdf_image_z_free(t_main *main);
void			fdf_image_z_clean(t_main *main);

void			fdf_graphics(t_main *main);
void			fdf_image_init(t_main *main);
void			fdf_graphics_close(t_main *main);
int				fdf_graphics_keypress(int keycode, t_main *main);
void			fdf_draw_points(t_main *main);
void			my_mlx_pixel_put(t_main *main, int x, int y, int color);
void			fdf_clean_win(t_main *main);
int				fdf_push_loop(t_main *main);
int				fdf_offsetx(t_main *main, double x);
int				fdf_offsety(t_main *main, double y);
void			fdf_move(t_main *main, int keycode);
int				fdf_mouse_scroll(int button, int x, int y, t_main *main);
int				fdf_scaling(t_main *main, double data);
void			fdf_isometric(t_main *main);
void			fdf_altitudemod(t_main *main, int i);
void			fdf_draw_lines(t_main *main);
void			fdf_draw_vertex(t_main *main, t_vertex vertex);
int				fdf_should_draw(t_main *main, t_vertex vertex);
void			fdf_put_z(t_main *main, int x, int y, int z);
void			fdf_put_pixel(t_main *main, int x, int y, int color);

void			fdf_event(t_main *main, int c);

int				fdf_color_shift(double index, int color0, int color1);
int				fdf_color2_vertex(t_main *main, t_vertex vertex);

#endif