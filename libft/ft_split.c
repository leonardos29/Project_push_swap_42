/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:16:21 by leonasil          #+#    #+#             */
/*   Updated: 2025/10/08 14:25:36 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*remove_tabs(const char *s)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*new_s;

	len = 0;
	while (s[len])
		len++;
	new_s = malloc(len + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '\t')
		{
			new_s[j] = s[i];
			j++;
		}
		new_s[j++] = ' ';
		i++;
	}
	new_s[j] = '\0';
	return (new_s);
}

static size_t	count_words(char const *s, char separator)

{
	size_t	count;
	int		inside_words;

	count = 0;
	while (*s)
	{
		inside_words = 0;
		while (*s == separator && *s)
			s++;
		while (*s != separator && *s)
		{
			if (!inside_words)
			{
				count++;
				inside_words = 1;
			}
			s++;
		}
	}
	return (count);
}

static int	allocate_memory(char **arr, int arr_position, size_t size)
{
	int	i;

	i = 0;
	arr[arr_position] = malloc(size);
	if (!arr[arr_position])
	{
		while (i < arr_position)
		{
			free (arr[i]);
			i++;
		}
		free (arr);
		return (1);
	}
	return (0);
}

static int	create_arr(char	**arr, const char *s, char separator)
{
	size_t		len;
	int			i;
	const char	*w_start;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == separator && *s)
			s++;
		w_start = s;
		while (*s != separator && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (allocate_memory(arr, i, len + 1))
				return (1);
			ft_strlcpy(arr[i], w_start, len + 1);
			i++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	number_of_words;
	char	**words_arr;
	char	*split_char;

	if (!s)
		return (NULL);
	split_char = remove_tabs(s);
	number_of_words = count_words(split_char, c);
	words_arr = malloc((number_of_words + 1) * sizeof(char *));
	if (!words_arr)
		return (NULL);
	words_arr[number_of_words] = NULL;
	if (create_arr(words_arr, split_char, c))
		return (NULL);
	return (words_arr);
}
