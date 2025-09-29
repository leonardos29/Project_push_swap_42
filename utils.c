/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:48:07 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/25 14:16:36 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char op_type, char stk_id, int is_reverse)
{
	if (op_type == 'p')
		ft_putchar_fd('p', 1);
	else if (op_type == 's')
		ft_putchar_fd('s', 1);
	else if (op_type == 'r')
	{
		if (is_reverse < 0)
			write(1, "r", 1);
		write(1, "r", 1);
	}
	ft_putchar_fd(stk_id, 1);
	ft_putchar_fd('\n', 1);
}

void	move_two_smallest(t_node **src_stk, t_node **dest_stk, size_t t_size)
{
	size_t	n_moved;
	t_node	*smallest_node;

	n_moved = 0;
	while (n_moved < t_size - 3)
	{
		smallest_node = find_min_value_node(*src_stk);
		if (smallest_node->original_pos > t_size / 2)
		{
			while ((*src_stk)->value != smallest_node->value)
				reverse_rotate_stk(src_stk, 'a');
		}
		else
		{
			while ((*src_stk)->value != smallest_node->value)
				rotate_stk(src_stk, 'a');
		}
		push(src_stk, dest_stk, 'b');
		n_moved++;
		free(smallest_node);
	}
}

void	sort_three_elements(t_node **stk, int values[3])
{
	if (values[0] > values[1] && values[0] < values[2])
		swap_from_stk_id(stk, 'a');
	else if (values[0] > values[1] && values[0] > values[2])
	{
		if (values[1] > values[2])
		{
			swap_from_stk_id(stk, 'a');
			reverse_rotate_stk(stk, 'a');
		}
		else
			rotate_stk(stk, 'a');
	}
	else if (values[0] < values[1] && values[0] < values[2])
	{
		swap_from_stk_id(stk, 'a');
		rotate_stk(stk, 'a');
	}
	else
		reverse_rotate_stk(stk, 'a');
}
