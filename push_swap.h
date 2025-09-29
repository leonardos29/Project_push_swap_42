/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonasil <leonasil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:06:31 by leonasil          #+#    #+#             */
/*   Updated: 2025/09/25 14:06:32 by leonasil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	long			sorted_i;
	size_t			original_pos;
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_node_data
{
	size_t	original_pos;
	int		value;
	long	sorted_i;
}	t_node_data;

void	sort_num(size_t n_elements, char **elements);
t_node	*array_to_stk(size_t n_elements, char **elements);
t_node	*create_node(int value, size_t position, long sorted_i);
int		check_dup(t_node *stk_head, int value);
void	add_node_to_start(t_node **stk_head, t_node *new_node);
void	add_node_to_end(t_node **stk_head, t_node *new_node);
t_node	*get_last_node(t_node *head);
t_node	*find_min_value_node(t_node *stk_head);
int		ft_atoi_and_check(const char *str, long *result);
int		is_stk_sorted(t_node *node);
void	clear_lst(t_node **stk_head);
void	free_str_arr(char **str_arr);
void	print_op(char op_type, char stk_id, int is_reverse);
void	move_two_smallest(t_node **src_stack, t_node **dest_stack,
			size_t total_size);
void	sort_three_elements(t_node **stk, int values[3]);
void	swap_from_stk_id(t_node **stk_head, char stack_id);
void	swap_both_stks(t_node **first_stack, t_node **second_stack);
void	push(t_node **src_stack, t_node **dest_stack, char stack_id);
void	rotate_stk(t_node **stack, char stack_id);
void	reverse_rotate_stk(t_node **stack, char stack_id);
void	rotate_both_stks(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_both_stks(t_node **stack_a, t_node **stack_b);

#endif
