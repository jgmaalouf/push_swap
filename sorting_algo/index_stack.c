/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:22:32 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 03:16:01 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

void	set_index(int min, t_stack_node **head, int index)
{
	t_stack_node	*tmp;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->data == min)
		{
			tmp->index = index;
			return ;
		}
		tmp = tmp->next;
	}
	return ;
}

int	minimum(t_stack_node **head)
{
	int				min;
	t_stack_node	*tmp;

	tmp = *head;
	while (tmp->index >= 0)
		tmp = tmp->next;
	min = tmp->data;
	while (tmp != NULL)
	{
		if (tmp->data < min && tmp->index < 0)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

void	index_stack(t_stack_node **head, int max_index)
{
	int	index;

	index = 0;
	while (index <= max_index)
	{
		set_index(minimum(head), head, index);
		index++;
	}
}

void	reset_index(t_stack_node **head)
{
	t_stack_node	*iterator;

	iterator = *head;
	while (iterator != NULL)
	{
		iterator->index = -1;
		iterator = iterator->next;
	}
}

void	make_data_increment_1(t_stack_node **head_a)
{
	t_stack_node	*iterator;

	iterator = *head_a;
	while (iterator != NULL)
	{
		iterator->data = iterator->index;
		iterator = iterator->next;
	}
}
