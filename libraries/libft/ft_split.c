/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:08:22 by maolivei          #+#    #+#             */
/*   Updated: 2022/05/14 18:47:40 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
* @brief Allocates and fills the array of strings created
* in ft_split().
* @param split The array that will contain the strings.
* @param s String to be splitted.
* @param c Character used as delimiter.
* @param words How many words to split string s in.
* @return A pointer to the created array of strings or NULL on error.
*/
static char	**ft_fill_split(char **split, const char *s, char c, int words)
{
	int		start;
	int		end;
	int		index;

	start = 0;
	index = 0;
	while (index < words)
	{
		while (s[start] == c)
			start += 1;
		end = start;
		while (s[end] != c && s[end])
			end += 1;
		split[index] = (char *)ft_calloc((end - start) + 1, sizeof(char));
		if (!split[index])
		{
			ft_free_split(split);
			return (NULL);
		}
		ft_strlcpy(split[index], s + start, (end - start) + 1);
		start = end;
		index += 1;
	}
	return (split);
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
	int	words;
	int	is_word;

	words = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			words += 1;
			is_word = 1;
		}
		if (*s == c)
			is_word = 0;
		s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	words = ft_count_words(s, c);
	split = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_fill_split(split, s, c, words);
	if (!split)
		return (NULL);
	split[words] = NULL;
	return (split);
}
