/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonardo_ouza <leonardo_ouza@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:22:25 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/23 21:59:33 by leonardo_ou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stk(t_node **stk_a, t_node **stk_b, size_t total_size)
{
	int		top_three_values[3];
	size_t	count;

	count = 0;
	if (total_size > 3)
		move_two_smallest(stk_a, stk_b, total_size);
	top_three_values[0] = (*stk_a)->value;
	top_three_values[1] = (*stk_a)->next->value;
	top_three_values[2] = (*stk_a)->next->next->value;
	if (!is_stk_sorted(*stk_a))
		sort_three_elements(stk_a, top_three_values);
	if (total_size > 3)
	{
		while (count < total_size - 3)
		{
			push(stk_b, stk_a, 'a');
			count++;
		}
	}
}
void	radix_sort(t_node **stackA, int total_elements)
{
	int		bit_position;
	int		max_bits;
	int		count;
	t_node	*stackb;

	bit_position = 0;
	stackb = NULL;
	max_bits = 0;
	while (((total_elements - 1) >> max_bits) != 0)
		max_bits++;
	while (bit_position < max_bits)
	{
		count = 0;
		while (count < total_elements)
		{
			if ((((*stackA)->sorted_i >> bit_position) & 1) == 0)
				push(stackA, &stackb, 'b');
			else
				rotate_stk(stackA, 'a');
			count++;
		}
		while (stackb)
			push(&stackb, stackA, 'a');
		bit_position++;
	}
}hhhhh
void sort_num(size_t n_elements, char **elements)
{
    t_node *stack_a;
    t_node *stack_b;

    stack_a = array_to_stk(n_elements, elements);
    stack_b = NULL;
    if (!stack_a)
        write(2,"Error\n",6);
    else if (is_stk_sorted(stack_a))
    {
        clear_lst(&stack_a);
        return;
    }
    else if (n_elements < 6 && n_elements > 2)
        sort_small_stk(&stack_a, &stack_b, n_elements);
    else if (n_elements == 2)
        swap_from_stk_id(&stack_a, 'a');
    else
        radix_sort(&stack_a, n_elements);
    clear_lst(&stack_a);
}
/*
void sort_num(size_t n_elements, char **elements)
{
    t_node *stack_a;
    t_node *current;

    stack_a = array_to_stk(n_elements, elements);
    if (!stack_a)
    {
        write(2, "Error\n", 6);
        return;
    }

    // percorre e imprime a stack
    current = stack_a;
    while (current)
    {
        printf("Value: %d | Pos: %zu | Sorted_i: %ld\n",
               current->value,
               current->original_pos,
               current->sorted_i);
        current = current->next;
    }
     clear_lst(&stack_a);
}
*/