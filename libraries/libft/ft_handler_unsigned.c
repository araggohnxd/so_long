/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:51:07 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/09 16:06:47 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handler_unsigned(t_uint uint)
{
	size_t	num_size;

	num_size = 1;
	ft_putnbr_fd(((long) uint), 1);
	while (uint >= 10)
	{
		uint /= 10;
		num_size++;
	}
	return (num_size);
}
