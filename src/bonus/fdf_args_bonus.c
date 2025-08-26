/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_args_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:41:17 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/05 19:53:17 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_finfo	fdf_find_window_size(t_main *main)
{
	int		i;
	t_finfo	finfo;

	i = 0;
	finfo = main->finfo;
	while (finfo.args[i] == ' ')
		i++;
	while (finfo.args[i] != ' ')
		i++;
	finfo.w_width = ft_atolle(finfo.args, &i);
	if (i == -1)
		fdf_error(main, "Error in fdf_find_window_size : No width\n");
	if (finfo.w_width > 1920 || finfo.w_width <= 0)
		fdf_error(main, "Error in fdf_fin_window_size : \
			Width not in range of 0-1920 pixels\n");
	finfo.w_height = ft_atolle(finfo.args, &i);
	if (i == -1)
		fdf_error(main, "Error in fdf_find_window_size : No height\n");
	if (finfo.w_height > 1080 || finfo.w_height <= 0)
		fdf_error(main, "Error in fdf_fin_window_size : \
			height not in range of 0-1080 pixels\n");
	return (finfo);
}

static void	fdf_window_size_init(t_main *main)
{
	main->finfo.w_height = DEFAULT_WINDOW_HEIGHT;
	main->finfo.w_width = DEFAULT_WINDOW_WIDTH;
	main->finfo.w_border = DEFAULT_WINDOW_BORDER;
}

static void	fdf_error_filename(t_main *main)
{
	int		ifile;
	int		iname;
	char	*filename;

	filename = main->finfo.filename;
	ifile = 0;
	iname = 0;
	while (filename[ifile])
	{
		if (filename[ifile] == '/')
			iname = ifile + 1;
		ifile++;
	}
	ifile--;
	while (filename[ifile] == ' ')
		ifile--;
	if (ifile - iname <= 3)
		fdf_error(main, "Error in fdf_error_filename : filename too short\n");
	if (filename[ifile] != 'f' || filename[ifile - 1] != 'd' || \
		filename[ifile - 2] != 'f' || filename[ifile - 3] != '.')
		fdf_error(main, "Error in fdf_Error_filename function : \
			Wrong extension\n");
}

void	fdf_args(t_main *main, char **args)
{
	int	argscount;

	main->finfo.args = ft_argjoin(args, ' ');
	if (!main->finfo.args)
		fdf_error(main, "Error in fdf_args function : Malloc\n");
	argscount = ft_countword(main->finfo.args, ' ');
	if (argscount > 3)
		fdf_error(main, "Error in fdf_args function : Too many arguments\n");
	main->finfo.filename = ft_firstword(main->finfo.args, ' ');
	if (!main->finfo.filename)
		fdf_error(main, "Error in fdf_error_args function : Malloc\n");
	fdf_error_filename(main);
	fdf_window_size_init(main);
	if (argscount > 1)
		main->finfo = fdf_find_window_size(main);
}
