/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:47:39 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/26 11:55:46 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	store_in_better_args(char **split_res, char **better_args)
{
	int	i;
	int	j;

	i = 0;
	while (better_args[i] != NULL)
		i++;
	j = 0;
	while (split_res[j] != NULL)
	{
		better_args[i] = split_res[j];
		i++;
		j++;
	}
	free(split_res);
}

int	freiheit(char **args, t_stack_node *head_a, t_stack_node *head_b, int argc)
{
	int				i;
	t_stack_node	*free_master;

	i = 0;
	while (i < argc)
	{
		free(args[i]);
		i++;
	}
	free(args);
	while (head_a != NULL)
	{
		free_master = head_a;
		head_a = head_a->next;
		free(free_master);
	}
	while (head_b != NULL)
	{
		free_master = head_b;
		head_b = head_b->next;
		free(free_master);
	}
	return (0);
}

int	sorted(t_stack_node **head_a)
{
	t_stack_node	*iterator;

	iterator = *head_a;
	if (iterator != NULL)
	{
		while (iterator->next != NULL)
		{
			if (iterator->data > iterator->next->data)
				return (0);
			iterator = iterator->next;
		}
	}
	return (1);
}

char	**parse_args(char **argv, int *wc)
{
	int		i;
	char	**better_args;

	i = 1;
	*wc = 0;
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
	if (non_numeric_input(args, wc) || duplicates(args, wc)
		|| out_of_range(args, wc))
		return (write(2, "Error\n", 6));
	return (0);
}
