/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:30:27 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 23:25:21 by eschussl         ###   ########.fr       */
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

typedef struct s_main
{
	t_finfo	file_info;
	t_parsing	*list;
	t_map	map;
	void	*mlx;
	void	*win;
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

void	fdf_error(t_main *main, char *error_message);

void	fdf_display_list(t_main *main);
void	fdf_display_map(t_main *main, char c);
void	fdf_display_vertex(t_main *main, int y, int x);

void	fdf_main_init(t_main *main);

#endif