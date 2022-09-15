/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:53:25 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/25 13:47:04 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack_node	*new_node(int digit)
{
	t_stack_node	*node;

	node = NULL;
	node = malloc(sizeof(t_stack_node));
	if (node != NULL)
	{
		node->data = digit;
		node->index = -1;
		node->next = NULL;
		return (node);
	}
	return (NULL);
}

int	stack(int digit, t_stack_node **head)
{
	t_stack_node	*tmp;

	if (*head == NULL)
		*head = new_node(digit);
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node(digit);
		if (tmp->next == NULL)
			return (-1);
	}
	return (0);
}

t_stack_node	*make_stack_a(int node_count, char **node_content)
{
	t_stack_node	*head;
	t_stack_node	*free_master;
	int				i;

	head = NULL;
	i = 0;
	while (i < node_count)
	{
		if (stack(ft_atoi(node_content[i++]), &head) == -1)
		{
			while (head != NULL)
			{
				free_master = head;
				head = head->next;
				free(free_master);
			}
			free(head);
			return (NULL);
		}
	}
	return (head);
}

int	not_valid(char **argv, char **args, int wc)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "") == 0 || ft_strcmp(argv[i], " ") == 0
			|| ft_strcmp(argv[i], "	") == 0)
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
		i++;
	}
	return (0);
}
