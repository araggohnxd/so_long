/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:39:59 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/01 00:25:00 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*start_dest;
	char	*start_src;

	start_dest = (char *) dest;
	start_src = (char *) src;
	if (dest > src)
	{
		while (n-- > 0)
			start_dest[n] = start_src[n];
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
