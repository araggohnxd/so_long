/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:17:10 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/05 22:06:31 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		result;
	int		min_count;

	i = 0;
	result = 0;
	min_count = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			min_count++;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
		result = (result * 10) + (nptr[i++] - '0');
	if (min_count % 2 == 1)
		return (-result);
	return (result);
}
