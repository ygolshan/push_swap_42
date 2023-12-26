/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:41:13 by ygolshan          #+#    #+#             */
/*   Updated: 2023/04/28 21:08:55 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_a(t_node **a, t_node **b)
{
	int	cheapest_pos;

	while (*b)
	{
		assign_status(a, b);
		find_cost(a, b);
		cheapest_pos = find_cheapest(b);
		regulate(cheapest_pos, a, b);
		push(a, b, "pa");
	}
}

void	send_to_b_and_sort(t_node **a, t_node **b)
{
	send_to_b_by_mid_point(a, b);
	sort_three(a);
}

void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
	{
		free_linked_list(a);
		exit(0);
	}
	else if (find_len(*a) == 2)
		swap(*a, "sa");
	else if (find_len(*a) == 3)
		sort_three(a);
	else if (find_len(*a) > 3)
		send_to_b_and_sort(a, &b);
	push_to_a(a, &b);
	reset_a(a, 0);
	free_linked_list(&b);
}
