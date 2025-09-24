/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:48:07 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/23 20:47:02 by leonardo_ou      ###   ########.fr       */
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
void	move_two_smallest(t_node **src_stack, t_node **dest_stack, size_t total_size)
{
	size_t	n_moved;
	t_node	*smallest_node;

	n_moved = 0;
	while (n_moved < total_size - 3)
	{
		smallest_node = find_min_value_node(*src_stack);
		if (smallest_node->original_pos > total_size / 2)
		{
			while ((*src_stack)->value != smallest_node->value)
				reverse_rotate_stk(src_stack, 'a');
		}
		else
		{
			while ((*src_stack)->value != smallest_node->value)
				rotate_stk(src_stack, 'a');
		}
		push(src_stack, dest_stack, 'b');
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

