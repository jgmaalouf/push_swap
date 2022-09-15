/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:47:39 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/27 15:06:17 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	freiheit(char **args, t_stack_node *head_a, int argc)
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
	free(head_a);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i++;
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
