/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:21:27 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/23 20:40:23 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_node_to_end(t_node **stk_head, t_node *new_node)
{
    t_node *current_node;
    
    if(!(*stk_head))
    {
        *stk_head = new_node;
        return;
    }
    current_node = *stk_head;
    while(current_node->next != NULL)
    	current_node = current_node->next;
    current_node->next = new_node;
    new_node->prev = current_node;
}
int	is_stk_sorted(t_node *node)
{
	while(node->next != NULL)
	{
		if(node->next->value > node->value)
			node = node->next;
		else
			return(0);
	}
	return(1);
}
void	add_node_to_start(t_node **stk_head, t_node *new_node)
{
	t_node	*current_node;

	if (!*stk_head)
	{
		new_node->next = NULL;
		*stk_head = new_node;
		return ;
	}
	new_node->next = *stk_head;
	*stk_head = new_node;
	current_node = *stk_head;
	current_node = current_node->next;
	while (current_node != NULL)
	{
		current_node->original_pos += 1;
		current_node = current_node->next;
	}
}
t_node	*get_last_node(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}
t_node	*find_min_value_node(t_node *stk_head)
{
	t_node	*min_value_node;

	min_value_node = create_node(stk_head->value, stk_head->original_pos,
			stk_head->sorted_i);
	while (stk_head)
	{
		if (stk_head->value < min_value_node->value)
		{
			min_value_node->value = stk_head->value;
			min_value_node->original_pos = stk_head->original_pos;
		}
		stk_head = stk_head->next;
	}
	return (min_value_node);
}