/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:22:28 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/25 13:59:38 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	char	**input;
	size_t	num_elements;
	char	**split_numbers;

	input = argv;
	num_elements = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split_numbers = ft_split(input[1], ' ');
		while (split_numbers[num_elements])
			num_elements++;
		sort_num(num_elements, split_numbers);
		free_str_arr(split_numbers);
	}
	else
	{
		input++;
		sort_num(argc - 1, input);
	}
	return (0);
}
