/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:57:33 by eschussl          #+#    #+#             */
/*   Updated: 2024/02/25 18:15:08 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start > (unsigned int) ft_strlen(s))
	{
		str = malloc (sizeof(const char));
		if (!str)
			return (fd_printf(2, "Error\n"), NULL);
		str[i] = '\0';
		return (str);
	}
	if (len > (size_t)ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = malloc (sizeof(const char) * len + 1);
	if (!str)
		return (fd_printf(2, "Error\n"), NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
