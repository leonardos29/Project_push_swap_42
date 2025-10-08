/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:42:01 by leonardo_ou       #+#    #+#             */
/*   Updated: 2025/10/08 13:43:30 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_and_check(const char *str, long *result)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!*str)
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			*result = (*result * 10) + (str[i++] - '0');
		else
			return (1);
		if (*result * sign > MAX_INT || *result * sign < MIN_INT)
			return (1);
	}
	*result = *result * sign;
	return (0);
}

int	check_dup(t_node *stk_head, int value)
{
	t_node	*current_node;

	if (!stk_head)
		return (0);
	current_node = stk_head;
	while (current_node)
	{
		if (current_node->value == value)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}
