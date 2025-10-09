/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:16:21 by leonasil          #+#    #+#             */
/*   Updated: 2025/10/09 21:25:12 by leonasil         ###   ########.fr       */
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

static size_t	count_words(char const *s, char separator)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == separator && *s)
			s++;
		if (!*s)
			break ;
		if (*s == '+' || *s == '-')
			s++;
		while (*s && *s != separator)
			s++;
		count++;
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
			free(arr[i]);
			i++;
		}
		free(arr);
		return (1);
	}
	return (0);
}

void	create_arr(char **arr, const char *s, char sep)
{
	size_t		len;
	int			i;
	const char	*w_start;

	i = 0;
	while (*s)
	{
		while (*s == sep && *s)
			s++;
		w_start = s;
		len = 0;
		if (*s == '+' || *s == '-')
		{
			s++;
			len++;
		}
		while (*s && *s != sep)
		{
			s++;
			len++;
		}
		if (allocate_memory(arr, i, len + 1))
			return ;
		ft_strlcpy(arr[i++], w_start, len + 1);
	}
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
	create_arr(words_arr, split_char, c);
	free(split_char);
	if (!words_arr[0])
		return (NULL);
	return (words_arr);
}
