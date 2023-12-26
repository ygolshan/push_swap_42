/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:38:40 by ygolshan          #+#    #+#             */
/*   Updated: 2023/04/28 14:23:22 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_dup2(t_node **a, long num)
{
	t_node	*temp1;
	t_node	*temp2;

	temp1 = *a;
	temp2 = NULL;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp2->data == (int)num)
				return (1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (0);
}

static void	free_stuff(long num, t_node **a, char ***str)
{
	if (num > INT_MAX || num < INT_MIN || check_dup2(a, num))
	{
		free_linked_list(a);
		free_array(str);
		handle_error(0);
	}
}

void	create_stack(char **storage, t_node **a)
{
	t_node	*nod;
	long	num;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(*storage, ' ');
	free(*storage);
	while (str[i])
	{
		num = ft_atoi(str[i]);
		free_stuff(num, a, &str);
		nod = malloc(sizeof(t_node));
		nod->data = num;
		nod->next = NULL;
		nod->sort_index = 0;
		if (!*a)
			(*a) = nod;
		else
			lstlast(*a)->next = nod;
		i++;
	}
	free_array(&str);
}

int	count_forward_moves(t_node *stack, int point)
{
	int	moves;

	moves = 0;
	while (stack != NULL && stack->sort_index != point)
	{
		moves++;
		stack = stack->next;
	}
	return (moves);
}

int	count_backward_moves(t_node *stack, int point)
{
	int	moves;

	moves = 0;
	while (stack->sort_index != point)
		stack = stack->next;
	while (stack != NULL)
	{
		moves++;
		stack = stack->next;
	}
	return (moves);
}
