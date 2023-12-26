/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:40:45 by ygolshan          #+#    #+#             */
/*   Updated: 2023/04/28 20:45:18 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_status(t_node **a, t_node **b)
{
	t_node	*temp;
	int		i;

	temp = *a;
	i = 0;
	while (temp != NULL)
	{
		temp->pos = i++;
		temp = temp->next;
	}
	temp = *b;
	i = 0;
	while (temp != NULL)
	{
		temp->pos = i++;
		temp = temp->next;
	}
}
