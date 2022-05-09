/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:29:36 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/10 02:08:29 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fill an array allocated with malloc() with the given
 * number received at ft_itoa().
 * @param num Number to fill the array with.
 * @param arr Pointer to the array to fill.
 * @param size Size of the number used to fill the array.
 * @return Nothing.
**/
static void	ft_fill_array(long num, char *arr, size_t size)
{
	if (num < 0)
	{
		arr[0] = '-';
		num = -num;
	}
	if (num >= 0)
	{
		if (num >= 10)
			ft_fill_array(num / 10, arr, size - 1);
		arr[size] = (num % 10) + '0';
	}
}

char	*ft_itoa(int n)
{
	char		*arr;
	long		num;
	int			is_negative;
	size_t		int_size;

	int_size = 1;
	is_negative = 0;
	num = n;
	if (n < 0)
		is_negative = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		int_size++;
	}
	arr = malloc(sizeof(char) * (int_size + is_negative + 1));
	if (arr == NULL)
		return (NULL);
	if (is_negative == 1)
		ft_fill_array(num, arr, int_size);
	else
		ft_fill_array(num, arr, int_size - 1);
	arr[int_size + is_negative] = '\0';
	return (arr);
}
