/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:08:22 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/14 16:43:36 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Fill the memory allocated in ft_malloc_strings() with its
* specific words.
* @param s String containing each word.
* @param c Character used as delimiter.
* @param split The array that will contain the words.
* @param size Number of words, calculated in ft_count_words().
* @return Nothing.
*/
static void	ft_fill_strings(const char *s, char c, char **split, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] && j < size)
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			split[j][k++] = s[i++];
		split[j][k] = '\0';
		j++;
	}
	split[j] = NULL;
}

/**
* @brief Allocate the memory needed for each word of the array
* of strings created in ft_split().
* @param s String containing each word.
* @param c Character used as delimiter.
* @param split The array that will contain the words.
* @param size Number of words, calculated in ft_count_words().
* @return 1 if the allocation was successful, 0 otherwise.
*/
static int	ft_malloc_strings(const char *s, char c, char **split, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	str_size;

	i = 0;
	j = 0;
	while (s[i] && j < size)
	{
		str_size = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i++] != c)
			str_size++;
		split[j] = malloc(sizeof(char) * (str_size + 1));
		if (split[j] == NULL)
		{
			ft_free_split(split);
			return (0);
		}
		j++;
	}
	return (1);
}

/**
* @brief Counts how many words will the array of strings
* created by ft_split() contain, using char c as a delimiter
* of each word inside string s.
* @param s String to count the words from.
* @param c Character used as delimiter.
* @return How many words were found.
*/
static int	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	str_count;

	i = 0;
	str_count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			j++;
			i++;
		}
		if (j > 0)
			str_count++;
	}
	return (str_count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	str_count;

	if (!s)
		return (NULL);
	str_count = ft_count_words(s, c);
	split = malloc(sizeof(char *) * (str_count + 1));
	if (split == NULL)
		return (NULL);
	if (!ft_malloc_strings(s, c, split, str_count))
		return (NULL);
	ft_fill_strings(s, c, split, str_count);
	return (split);
}
