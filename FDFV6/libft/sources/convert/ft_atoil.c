/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:07:39 by eschussl          #+#    #+#             */
/*   Updated: 2024/03/11 18:08:47 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoil(char *nptr, int *i)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (nptr[*i] == ' ' || (nptr[*i] >= 9 && nptr[*i] <= 13))
		*i += 1;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			sign = -sign;
		*i += 1;
	}
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		res = res * 10 + (nptr[*i] - '0');
		*i += 1;
	}
	return (res * sign);
}