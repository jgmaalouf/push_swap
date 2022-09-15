/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_to_a_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:01:55 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 03:17:00 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

int	if_data_1_data_2(t_stack_node **head_b, int data)
{
	if (abs_val(rots(head_b, data - 1)) <= abs_val(rots(head_b, data - 2)))
		return (data - 1);
	else
		return (data - 2);
}

int	if_one_data(t_stack_node **head_b, int data)
{
	if (data_is_in(head_b, data))
		return (data);
	else if (data_is_in(head_b, data - 1))
		return (data - 1);
	else
		return (data - 2);
}

void	send_3_num(t_stack_node **head_a, t_stack_node **head_b, int data)
{
	while (data_is_in(head_b, data) || data_is_in(head_b, data - 1)
		|| data_is_in(head_b, data - 2))
	{
		rotate_stack(rots(head_b, find_fastest(head_b, data)), head_b);
		push_a(head_b, head_a);
	}
}
