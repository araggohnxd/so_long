/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:15:24 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/08 11:58:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	substr;

	string = (unsigned char *) s;
	substr = (unsigned char) c;
	while (n--)
	{
		if (*string == substr)
			return (string);
		string++;
	}
	return (NULL);
}
