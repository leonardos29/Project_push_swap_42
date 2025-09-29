/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:55:57 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/09/25 14:05:37 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_lst(t_node **stk_head)
{
	t_node	*current_node;

	if (!*stk_head)
		return ;
	while (*stk_head)
	{
		current_node = (*stk_head)->next;
		free(*stk_head);
		*stk_head = current_node;
	}
	*stk_head = NULL;
}

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}
