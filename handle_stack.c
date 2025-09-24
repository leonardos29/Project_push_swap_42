/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:52:45 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/23 18:10:47 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_node(int value, size_t position, long sorted_i)
{
    t_node *new_node;
    
    new_node = (t_node *)malloc(sizeof(t_node));
    if(!new_node)
        return(0);
    new_node->value = value;
	new_node->original_pos = position;
	new_node->sorted_i = sorted_i;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}
t_node	*get_next_smallest_node(t_node *stk_head)
{
	t_node	*small_node;
	t_node	*current;

	current = stk_head;
	while (current)
	{
		if (current->sorted_i < 0)
		{
			small_node = create_node(current->value, current->original_pos,
					current->sorted_i);
			break ;
		}
		current = current->next;
	}
	while (stk_head)
	{
		if (stk_head->value < small_node->value && stk_head->sorted_i < 0)
		{
			small_node->value = stk_head->value;
			small_node->original_pos = stk_head->original_pos;
			small_node->sorted_i = stk_head->sorted_i;
		}
		stk_head = stk_head->next;
	}
	return (small_node);
}
void	set_sorted_indices(t_node *stk_head, size_t total_nodes)
{
	t_node	*smallest_n;
	t_node	*current_n;
	size_t	i;

	i = 0;
	while(i < total_nodes)
	{
		current_n = stk_head;
		smallest_n = get_next_smallest_node(stk_head);
		while(current_n)
		{
			if (current_n->value == smallest_n->value)
			{
				current_n->sorted_i = i;
				break ;
			}
			current_n = current_n->next;
		}
		free(smallest_n);
		i++;
	}
}
t_node  *create_node_from_arr(char *str, size_t *position)
{
    t_node *new_node;
    long value;

    value = 0;
    if(ft_atoi_and_check(str,&value))
        return (NULL);
    new_node = create_node(value, *position, -1);
    return (new_node);
}
t_node  *array_to_stk(size_t n_elements, char **elements)
{
    size_t i;
    t_node  *new_node;
    t_node  *stk;

    i = 0;
    stk = NULL;
    while(i < n_elements)
    {
        new_node = create_node_from_arr(elements[i], &i);
        if (!new_node || check_dup(stk, new_node->value))
        {
            if(new_node)
                free(new_node);
			clear_lst(&stk);
            return (NULL);
        }
        add_node_to_end(&stk, new_node);
		i++;
    }
    set_sorted_indices(stk, n_elements);
	return (stk);
}