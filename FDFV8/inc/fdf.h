/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 23:24:48 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 12:32:48 by eschussl         ###   ########.fr       */
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

/*##########################################################################
#                                                                           #
#                                  INCLUDES                                 #
#                                                                           #
 ##########################################################################*/

# include "libft.h"
# include <mlx.h>

/*##########################################################################
#                                                                           #
#                                 STRUCTURES                                #
#                                                                           #
 ##########################################################################*/

typedef struct s_finfo		t_finfo;
typedef struct s_data		t_data;
typedef struct s_vertex		t_vertex;
typedef struct s_minfo		t_minfo;
typedef struct s_event		t_event;
typedef struct s_colors		t_colors;
typedef struct s_parsing	t_parsing;
typedef struct s_main		t_main;

struct s_finfo
{
	char	*args;
	char	*filename;
	int		w_width;
	int		w_height;
	int		w_border;
};

struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		center_x;
	int		center_y;
};

struct s_vertex
{
	double	val[2][3];
	int		color[2];
};

struct s_minfo
{
	int	width;
	int	height;
	int	zmin[2];
	int	zmax[2];
	int xmin;
	int xmax;
	int	ymin;
	int ymax;
};

struct s_event
{
	int	colormode;
	int	viewmode;
	int	linemode;
	int	x_angle;
	int	z_angle;
	double	scaling;
	int	z_mod;
};

struct s_colors
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
};

struct	s_parsing
{
	void *next;
	char *line;
};

struct	s_main
{
	t_finfo		finfo;
	void		*mlx;
	void		*win;
	t_data		image;
	int			**image_z;
	t_vertex	**vertices;
	t_minfo		minfo;
	t_event		event;
	t_colors	colors;
	t_parsing	*parsing;
};

/*##########################################################################
#                                                                           #
#                                 FUNCTIONS                                 #
#                                                                           #
 ##########################################################################*/

/*###########
#	INIT	#
###########*/

void		fdf_colors_init(t_main *main);
int			fdf_color_shift(double index, int color0, int color1);
void		fdf_scale_init(t_main *main);
void		fdf_image_init(t_main *main);
void		fdf_image_z_init(t_main *main);


/*###########
#	FREE	#
###########*/

void		fdf_error(t_main *main, char *error_message);
void		fdf_freeparsing(t_main *main);

/*###########
#  PARSING	#
###########*/

void		fdf_args(t_main *main, char **args);
void		fdf_mapping(t_main *main);
void		fdf_parsing(t_main *main);
void		fdf_map_info(t_main *main);
void		fdf_vertices(t_main *main);
t_vertex	**fdf_normilizing(t_main *main);

/*###########
#   PRINT	#
###########*/

void	fdf_print_list(t_parsing *pars);
void	fdf_print_vertices(t_main *main, char c);

/*###########
#  GRAPHICS	#
###########*/

void	fdf_graphics(t_main *main);
void	fdf_draw_first_points(t_main *main);
void 	fdf_draw_points(t_main *main);
int		fdf_offsety(t_main *main, double y);
int		fdf_offsetx(t_main *main, double x);
int		fdf_scaling(t_main *main, double data);
void	fdf_scaling_first(t_main *main);
void	fdf_put_pixel(t_main *main, t_vertex vertex);
void	fdf_clean_win(t_main *main);

/*###########
#   HOOKS	#
###########*/

int		fdf_hooks_keypress(int keycode, t_main *main);
void	fdf_hooks_close(t_main *main);
void	fdf_event(t_main *main, int c);
int		fdf_push_loop(t_main *main);
void	fdf_should_draw(t_main *main, t_vertex vertex);
int		fdf_angle(int keycode, t_main *main);
int		fdf_mouse_scroll(int button, int x, int y, t_main *main);

/*###########
#   LINES	#
###########*/

void	fdf_lines(t_main *main);
void	fdf_draw_line(t_main *main, t_vertex v1, t_vertex v2);
#endif