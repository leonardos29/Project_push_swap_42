/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:52 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/25 14:08:57 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stk(t_node **stack, char stack_id)
{
	t_node	*current;
	int		temp_value;
	long	temp_sorted_i;

	if (stack_id == 'a' || stack_id == 'b')
		print_op('r', stack_id, 1);
	if (!(*stack) || !(*stack)->next)
		return ;
	current = *stack;
	temp_value = current->value;
	temp_sorted_i = current->sorted_i;
	while (current->next)
	{
		current->value = current->next->value;
		current->sorted_i = current->next->sorted_i;
		current = current->next;
	}
	current->value = temp_value;
	current->sorted_i = temp_sorted_i;
}

void	reverse_rotate_stk(t_node **stack, char stack_id)
{
	t_node	*first_node;
	t_node	*last_node;
	int		temp_first_value;
	size_t	temp_first_sorted_i;

	if (stack_id == 'a' || stack_id == 'b')
		print_op('r', stack_id, -1);
	if (!(*stack)->next)
		return ;
	first_node = *stack;
	last_node = get_last_node(first_node);
	temp_first_value = last_node->value;
	temp_first_sorted_i = last_node->sorted_i;
	while (last_node->prev)
	{
		last_node->value = last_node->prev->value;
		last_node->sorted_i = last_node->prev->sorted_i;
		last_node = last_node->prev;
	}
	first_node->value = temp_first_value;
	first_node->sorted_i = temp_first_sorted_i;
}

void	rotate_both_stks(t_node **stack_a, t_node **stack_b)
{
	rotate_stk(stack_a, 's');
	rotate_stk(stack_b, 's');
	write(1, "rr\n", 3);
}

void	reverse_rotate_both_stks(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate_stk(stack_a, 's');
	reverse_rotate_stk(stack_b, 's');
	write(1, "rrr\n", 4);
}
