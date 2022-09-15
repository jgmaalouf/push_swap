/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:00:41 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/13 16:59:36 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_args(char **argv, int *wc)
{
	int		i;
	char	**better_args;

	i = 1;
	while (argv[i] != NULL)
	{
		*wc += word_count(argv[i], ' ');
		i++;
	}
	better_args = NULL;
	better_args = malloc((*wc) * sizeof(char *));
	if (better_args != NULL)
	{
		i = 1;
		while (argv[i] != NULL)
		{
			store_in_better_args(ft_split(argv[i], ' '), better_args);
			i++;
		}
		return (better_args);
	}
	return (NULL);
}

int	error_handling(char **args, int wc)
{
	int	i;

	if (non_numeric_input(args, wc) || duplicates(args, wc)
		|| out_of_range(args, wc))
	{
		i = 0;
		while (i < wc)
		{
			free(args[i]);
			i++;
		}
		free(args);
		return (1);
	}
	return (0);
}

int	push_swap(t_stack_node **head_a, int argc)
{
	t_stack_node	*head_b;

	head_b = NULL;
	index_stack(head_a, argc - 1);
	make_data_increment_1(head_a);
	if (!sorted(head_a))
		combine_sorts(head_a, &head_b, argc - 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack_node	*head_a;
	char			**args;
	int				wc;

	wc = 0;
	args = NULL;
	args = parse_args(argv, &wc);
	if (not_valid(argv, args, wc))
		return (write(2, "Error\n", 6));
	if (args != NULL)
	{
		argc = wc;
		if (error_handling(args, wc) != 0)
			return (write(2, "Error\n", 6));
		head_a = make_stack_a(argc, args);
		push_swap(&head_a, argc);
		freiheit(args, head_a, argc);
	}
	return (0);
}
