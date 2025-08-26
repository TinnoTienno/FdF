/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:41:17 by eschussl          #+#    #+#             */
/*   Updated: 2024/04/10 15:39:23 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	filename = main->finfo.args;
	ifile = 0;
	iname = 0;
	if (!filename[0])
		fdf_error(main, "Error in fdf_error_filename : no filename\n");
	while (main->finfo.args[ifile])
	{
		if (main->finfo.args[ifile] == '/')
			iname = ifile + 1;
		ifile++;
	}
	ifile--;
	while (main->finfo.args[ifile] == ' ')
		ifile--;
	if (ifile - iname <= 3)
		fdf_error(main, "Error in fdf_error_filename : filename too short\n");
	if (main->finfo.args[ifile] != 'f' || main->finfo.args[ifile - 1] \
		!= 'd' || main->finfo.args[ifile - 2] != 'f' || \
			main->finfo.args[ifile - 3] != '.')
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
	if (argscount > 1)
		fdf_error(main, "Error in fdf_args function : Too many arguments\n");
	main->finfo.filename = ft_firstword(main->finfo.args, ' ');
	if (!main->finfo.filename)
		fdf_error(main, "Error in fdf_error_args function : Malloc\n");
	fdf_error_filename(main);
	fdf_window_size_init(main);
}
