/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:06:53 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/25 18:14:41 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		size;
	char	*str;
	int		i;

	size = ft_strlen(s) + 1;
	str = malloc (sizeof(char) * size);
	if (!str)
		return (fd_printf(2, "Error\n"), NULL);
	i = 0;
	while (i < size - 1)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
