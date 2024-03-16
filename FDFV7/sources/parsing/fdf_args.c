/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:42:10 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 19:19:23 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static void fdf_find_window_size(t_main *main)
{
	int i;
	
	i = 0;
	while (main->file_info.args[i] == ' ')
		i++;
	while (main->file_info.args[i] != ' ')
		i++;
	main->file_info.window_width = ft_atolle(main->file_info.args, &i);
	if (i == -1)
		fdf_error(main, "Error in fdf_find_window_size : No width\n");
	if (main->file_info.window_width > 1920 || main->file_info.window_width <= 0)
		fdf_error(main, "Error in fdf_fin_window_size : Width not in range of 0-1920 pixels\n");
	main->file_info.window_height = ft_atolle(main->file_info.args, &i);
	if (i == -1)
		fdf_error(main, "Error in fdf_find_window_size : No height\n");
	if (main->file_info.window_height > 1080 || main->file_info.window_height <= 0)
		fdf_error(main, "Error in fdf_fin_window_size : height not in range of 0-1080 pixels\n");
	free (main->file_info.args);
	main->file_info.args = NULL;
}
static void fdf_window_size_init(t_main *main)
{
	main->file_info.window_height = DEFAULT_WINDOW_HEIGHT;
	main->file_info.window_width = DEFAULT_WINDOW_WIDTH;
	main->file_info.window_border = DEFAULT_WINDOW_BORDER;
}
static void	fdf_error_file(t_main *main)
{
	int sfile;
	int sname;

	sfile = 0;
	sname = 0;
	while (main->file_info.filename[sfile])
	{
		if (main->file_info.filename[sfile] == '/')
			sname = sfile + 1;
		sfile++;
	}
	sfile--;
	while (main->file_info.filename[sfile] == ' ')
		sfile--;
	if (sfile - sname <= 3)
		fdf_error(main, "Error in fdf_error_file function : filename too short\n");
	if (main->file_info.filename[sfile] != 'f' || main->file_info.filename[sfile - 1] != 'd' ||\
	main->file_info.filename[sfile - 2] != 'f' || main->file_info.filename[sfile - 3] != '.')
		fdf_error(main, "Error in fdf_error_file function : Wrong extension\n");
}
void	fdf_args(t_main *main, char **args)
{
	int	argscount;
	
	main->file_info.args = ft_argjoin(args, ' ');
	if (!main->file_info.args)
		fdf_error(main, "Error in fdf_error_args function : Malloc\n");
	argscount = ft_countword(main->file_info.args, ' ');
	if (argscount > 3)
		fdf_error(main, "Error in fdf_error_args function : Too many arguments");
	main->file_info.filename = ft_firstword(main->file_info.args, ' ');
	if (!main->file_info.filename)
		fdf_error(main, "Error in fdf_error_args function : Malloc\n");
	fdf_error_file(main);
	fdf_window_size_init(main);
	if (argscount > 1)
		fdf_find_window_size(main);
	// printf("check fdf_args :\nfilename : %s\nWindow_height : %d\nWindow_width : %d\nwindow_border : %d\n", main->file_info.filename, main->file_info.window_height, main->file_info.window_width, main->file_info.window_border);
}