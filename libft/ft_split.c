/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:16:21 by leonasil          #+#    #+#             */
/*   Updated: 2025/10/13 13:22:17 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stddef.h>

static char	*remove_tabs(const char *s)
{
	size_t	i;
	size_t	len;
	char	*new_s;

	len = 0;
	while (s[len])
		len++;
	new_s = malloc(len + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (s[i] == '\t')
			new_s[i] = ' ';
		else
			new_s[i] = s[i];
		i++;
	}
	new_s[len] = '\0';
	return (new_s);
}

static int	countword(const char *s, char c)
{
	int	i;
	int	countword;

	i = 0;
	countword = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			countword++;
		i++;
	}
	return (countword);
}

static void	*allocate_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	if (!s || start >= end)
		return (NULL);
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	**create_arr(char **bi_array, const char *s, char c)
{
	int	i;
	int	word_start;
	int	word_index;

	i = 0;
	word_index = 0;
	word_start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_start = i;
			while (s[i] && s[i] != c)
				i++;
			bi_array[word_index] = allocate_word(s, word_start, i);
			if (!bi_array[word_index])
				return (ft_free(bi_array, word_index));
			word_index++;
		}
		else
			i++;
	}
	return (bi_array);
}

char	**ft_split(char const *s, char c)
{
	char	**bi_array;
	char	*split_char;

	if (!s)
		return (NULL);
	split_char = remove_tabs(s);
	bi_array = ft_calloc(countword(split_char, c) + 1, sizeof(char *));
	if (!bi_array)
		return (NULL);
	bi_array = create_arr(bi_array, split_char, c);
	free(split_char);
	return (bi_array);
}
