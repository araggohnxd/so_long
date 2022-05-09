/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlinecpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:48:22 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/09 11:48:32 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_newlinecpy(char *dst, const char *src, size_t index)
{
	size_t	i;

	i = 0;
	while (src[i] != '\n' && src[i])
		dst[index++] = src[i++];
	if (src[i] == '\n')
		dst[index++] = '\n';
	dst[index] = '\0';
	return (index);
}
