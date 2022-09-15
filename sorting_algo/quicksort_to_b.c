/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:01:04 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 03:18:07 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

void	recieve_from_a(t_stack_node **head_a, t_stack_node **head_b, int max)
{
	if ((*head_b) != NULL && (*head_b)->index > (((max / 2) / 2) / 2)
		&& (*head_a)->index > (max / 2) / 2)
		rotate_ab(head_a, head_b);
	else
	{
		if ((*head_b) != NULL && (*head_b)->index > ((max / 2) / 2) / 2)
			rotate_b(head_b);
		if ((*head_a)->index > ((max / 2) / 2))
			rotate_a(head_a);
	}
}

int	send_to_b(t_stack_node **head_a, t_stack_node **head_b, int max)
{
	int	push_count;

	push_count = 0;
	while (push_count <= (max / 2) / 2)
	{
		if ((*head_a)->index <= (max / 2) / 2)
		{
			push_b(head_a, head_b);
			push_count++;
		}
		recieve_from_a(head_a, head_b, max);
	}
	return (push_count);
}

void	quicksort_to_b(t_stack_node **head_a,
	t_stack_node **head_b, int max_index)
{
	int	max;

	max = max_index;
	while ((*head_a) != NULL && max > 2)
	{
		reset_index(head_a);
		reset_index(head_b);
		index_stack(head_a, max);
		max = max - send_to_b(head_a, head_b, max);
	}
}
