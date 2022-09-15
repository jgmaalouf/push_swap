/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_to_a_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:07:06 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 03:17:23 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

int	if_all(t_stack_node **head_b, int data)
{
	if (abs_val(rots(head_b, data)) <= abs_val(rots(head_b, data - 1))
		&& abs_val(rots(head_b, data)) <= abs_val(rots(head_b, data - 2)))
		return (data);
	else if (abs_val(rots(head_b, data - 1)) <= abs_val(rots(head_b, data))
		&& abs_val(rots(head_b, data - 1)) <= abs_val(rots(head_b, data - 2)))
		return (data - 1);
	else
		return (data - 2);
}

int	if_data_data_1(t_stack_node **head_b, int data)
{
	if (abs_val(rots(head_b, data)) <= abs_val(rots(head_b, data - 1)))
		return (data);
	else
		return (data - 1);
}

int	if_data_data_2(t_stack_node **head_b, int data)
{
	if (abs_val(rots(head_b, data)) <= abs_val(rots(head_b, data - 2)))
		return (data);
	else
		return (data - 2);
}
