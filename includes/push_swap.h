/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:36:40 by ygolshan          #+#    #+#             */
/*   Updated: 2023/04/28 20:46:15 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct t_list
{
	int				data;
	int				sort_index;
	int				cost_a;
	int				cost_b;
	int				pos;
	int				cheapest;
	struct t_list	*next;
}					t_node;
void	push_swap(t_node **a);
void	regulate_rotate(t_node **a, t_node **b, t_node *temp);
void	swap_if_greater(t_node **stack, char *instruction,
			int first, int *second);
void	find_cost(t_node **a, t_node **b);
int		find_cheapest(t_node **b);
void	create_stack(char **storage, t_node **a);
t_node	*lstlast(t_node *lst);
int		is_sorted(t_node *stack);
void	handle_error(int nb);
void	free_array(char ***str);
void	free_linked_list(t_node **stack);
int		check_dup(char **str);
int		check_invalid_args(char **str);
void	swap(t_node *stack, char *str);
void	push(t_node **stack_1, t_node **stack_2, char *str);
void	rotate(t_node **stack, char *str, int cost);
void	reverse_rotate(t_node **stack, char *str, int cost);
void	push_a(t_node **stack_1, t_node **stack_2, char *str);
void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);
void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);
int		find_len(t_node *stack);
void	sort_int_array(int **tab, int size);
void	assign_index(int len, t_node **stack, int *sorted_list);
void	put_sorting_index(t_node **stack);
int		find_midpoint(t_node *stack);
int		count_forward_moves(t_node *stack, int point);
int		count_backward_moves(t_node *stack, int point);
int		get_target_index(t_node **a, t_node **b);
void	find_min_and_max(int *a_min, int *a_max, t_node *temp);
void	check_min_and_max_diff(int *min_pos_diff, int *max_diff,
			t_node **a, t_node **b);

int		calculate_cost(t_node *a, t_node *b);
int		list_size(t_node *head);

void	sort_three(t_node **stack);
void	send_to_b_by_mid_point(t_node **a, t_node **b);
void	send_to_b(t_node **a, t_node **b, int *total_nodes_to_go);
int		find_midpt(t_node *stack);
void	push_to_b(t_node **a, t_node **b, int *i, int *total_nodes_to_go);
void	reset_a(t_node **stack, int point);
void	assign_status(t_node **a, t_node **b);
void	regulate(int cheapest_pos, t_node **a, t_node **b);

#endif