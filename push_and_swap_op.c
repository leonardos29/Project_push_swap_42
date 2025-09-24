/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:41:34 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/23 20:44:03 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_from_stk_id(t_node **stk_head, char stack_id)
{
	t_node_data	temp;
	t_node		*first_node;
	t_node		*second_node;

	if (!*stk_head || (*stk_head)->next == NULL)
		return ;
	if (stack_id == 'a' || stack_id == 'b')
		print_op('s', stack_id, 0);
	first_node = *stk_head;
	second_node = first_node->next;
	temp.value = first_node->value;
	temp.original_pos = first_node->original_pos;
	temp.sorted_i = first_node->sorted_i;
	first_node->value = second_node->value;
	first_node->original_pos = second_node->original_pos;
	first_node->sorted_i = second_node->sorted_i;
	second_node->value = temp.value;
	second_node->original_pos = temp.original_pos;
	second_node->sorted_i = temp.sorted_i;
}
void	swap_both_stks(t_node **first_stack,t_node **second_stack)
{
	swap_from_stk_id(first_stack, 's');
	swap_from_stk_id(second_stack, 's');
	write(1, "ss\n", 3);
}
void	push(t_node **src_stack, t_node **dest_stack, char stack_id)
{
	t_node	*node_to_move;
	t_node	*new_top_node;

	if (stack_id == 'a' || stack_id == 'b')
		print_op('p', stack_id, 0);
	node_to_move = *src_stack;
	if ((*src_stack)->next)
		new_top_node = (*src_stack)->next;
	else
		new_top_node = NULL;
	add_node_to_start(dest_stack, node_to_move);
	if (!new_top_node)
	{
		*src_stack = NULL;
		return ;
	}
	new_top_node->prev = NULL;
	*src_stack = new_top_node;
}
