/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:12:06 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/08 14:22:17 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char) c)
			last = (char *) s;
		s++;
	}
	if (*s == (unsigned char) c)
		last = (char *) s;
	if (last == NULL)
		return (NULL);
	return (last);
}
