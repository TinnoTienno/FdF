/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:35:59 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/26 14:58:01 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define GWF_BUFFER_SIZE 5

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fdf_info_summary
{
	long	length;
	int width;
	int	altitudemin;
	int	altitudemax;
}	

typedef struct s_fdf_mapping
{
	
}

char	*gwf(int fd);

#endif