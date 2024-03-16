/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:07:18 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/16 21:32:45 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbvalue(int c, const char *base)
{
	int i;

	i = 0;
	while (base[i] && (c != ft_ctolower(base[i]) && c != ft_ctoupper(base[i])))
		i++;
	return (i);
}
static int	ft_error_alpha(int c, const char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == ft_ctolower(base[i]) || c == ft_ctoupper(base[i]))
			return (0);
		i++;
	}
	return (1);
}
// static int	ft_base_error(const char *str, const char *base)
// {
// 	int i;
	
// 	i = 0;
// 	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == ' '))
// 		i++;
// 	while (str[i])
// 	{
// 		if (ft_error_alpha(str[i], base) == 1)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }
int	ft_atoi_base(const char *str, const char *base)
{	
	int	i;
	int	sign;
	int	res;
	int baselen;
	
	baselen = (ft_strlen(base));
	// if (ft_base_error(str, base) == 1)
	// 	fd_printf(2, "Error input in FT_ATOI_BASE\n");
	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == ' ') && ft_error_alpha(str[i], base) ==  0)
	{
		if (i == 0 && str[i] == '-')
			sign = -sign;
		else
			res = res * baselen + ft_nbvalue(str[i], base);
		i++;
	}
	return (res);
}
