/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:07:18 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/26 21:07:41 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_checkbase(int c, int str_base)
{
	int i;
	char *str = "0123456789abcdef";
	char *STR = "0123456789ABCDEF";
	
	i = 0;
	while (i < str_base)
	{
		if (c == str[i] || c == STR[i])
			return (1);
		i++;
	}
	return (0);
}
static int ft_nbvalue(int c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	if (c >= 'A' && c <= 'F')
		return (10 + c - 'A');
	return (0);
}
int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			sign = -sign;
		else if(ft_checkbase(str[i], str_base) == 0)
			break;
		else
			res = res * str_base + ft_nbvalue(str[i]);
		i++;
	}
	return (res * sign);
}