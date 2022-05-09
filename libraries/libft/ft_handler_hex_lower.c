/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_hex_lower.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:13:01 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/09 16:06:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handler_hex_lower(t_uint num)
{
	size_t	num_size;
	char	*arr;

	arr = ft_itoa_base(num, HEX_BASE_LOWER);
	ft_putstr_fd(arr, 1);
	num_size = ft_strlen(arr);
	free(arr);
	return (num_size);
}
