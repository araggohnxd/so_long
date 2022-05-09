/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:38:42 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/09 16:06:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handler_pointer(t_ulong pointer_size)
{
	size_t	num_size;
	char	*arr;

	if (!pointer_size)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	arr = ft_itoa_base(pointer_size, HEX_BASE_LOWER);
	ft_putstr_fd(arr, 1);
	num_size = (ft_strlen(arr));
	free(arr);
	return (num_size + 2);
}
