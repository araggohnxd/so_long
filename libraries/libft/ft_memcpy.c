/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:55:16 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/08 11:58:12 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*start_dest;
	char	*start_src;

	if (!dest && !src)
		return (dest);
	start_dest = (char *) dest;
	start_src = (char *) src;
	while (n-- > 0)
		*start_dest++ = *start_src++;
	return (dest);
}
