/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sorts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:07:00 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/25 11:37:38 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

void	optimized_sort(t_stack_node **head_a, t_stack_node **head_b)
{
	rotate_stack_a(rots(head_a, 0), head_a);
	push_b(head_a, head_b);
	rotate_stack_a(rots(head_a, 1), head_a);
	push_b(head_a, head_b);
}

void	sort_leftovers_a(t_stack_node **head_a)
{
	if ((*head_a) != NULL && (*head_a)->next != NULL
		&& (*head_a)->next->next != NULL)
		sort_3(head_a);
	else if ((*head_a) != NULL && (*head_a)->next != NULL)
	{
		if ((*head_a)->index > (*head_a)->next->index)
			swap_a(head_a);
	}
}

void	insertion_sort(t_stack_node **head_a, t_stack_node **head_b)
{
	int	data;

	while ((*head_b) != NULL)
	{
		data = (*head_a)->data - 1;
		send_3_num(head_a, head_b, data);
		sort_3(head_a);
	}
}

void	combine_sorts(t_stack_node **head_a,
t_stack_node **head_b, int element_count)
{
	if (element_count < 3 && (*head_a)->next != NULL
		&& (*head_a)->next->next != NULL
		&& (*head_a)->next->next->next == NULL)
		return (sort_3_optimized(head_a));
	else if (element_count == 3 || element_count == 4)
		optimized_sort(head_a, head_b);
	else
		quicksort_to_b(head_a, head_b, element_count);
	sort_leftovers_a(head_a);
	insertion_sort(head_a, head_b);
}
