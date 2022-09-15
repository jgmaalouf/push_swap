/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:53:25 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/03 22:31:59 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*new_node(int digit)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	node->data = digit;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	stack(int digit, t_stack_node **head)
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
	}
}

t_stack_node	*make_stack_a(int node_count, char **node_content)
{
	t_stack_node	*head;
	int				i;

	head = NULL;
	i = 0;
	while (i < node_count)
		stack(ft_atoi(node_content[i++]), &head);
	return (head);
}
