/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:41:13 by ygolshan          #+#    #+#             */
/*   Updated: 2023/04/28 21:11:26 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*create_string_from_args(char **argv, char **storage);

int	main(int argc, char **argv)
{
	t_node	*a;
	char	*storage;

	if (argc < 2 || (argc == 2 && *argv[1] == ' ')
		|| (argc == 2 && !*argv[1]))
	{
		if (argc == 2 && *argv[1] == ' ')
			write(2, "Error\n", 6);
		return (0);
	}	
	else
	{
		storage = NULL;
		storage = create_string_from_args(argv, &storage);
		if (!check_invalid_args(&storage) || !check_dup(&storage))
			handle_error(0);
		a = NULL;
		create_stack(&storage, &a);
		put_sorting_index(&a);
		push_swap(&a);
		free_linked_list(&a);
		return (0);
	}
}

static char	*create_string_from_args(char **argv, char **storage)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i][0])
		{	
			free(*storage);
			handle_error(0);
		}
		*storage = ft_strjoin(*storage, argv[i++]);
		*storage = ft_strjoin(*storage, " ");
	}
	return (*storage);
}
