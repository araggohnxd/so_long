/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:01:34 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/03 23:08:02 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;
	char	*ptr;

	i = 0;
	j = 0;
	little_len = ft_strlen(little);
	ptr = (char *) big;
	if (!little_len)
		return (ptr);
	while (ptr[i] && i < len)
	{
		while (ptr[i] == little[j] && i < len)
		{
			j++;
			i++;
			if (j == little_len)
				return (ptr += i - little_len);
		}
		i -= j;
		j = 0;
		i++;
	}
	return (NULL);
}
