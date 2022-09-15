/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_find_fastest_rot.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:05:21 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 03:16:38 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

int	data_is_in(t_stack_node **head, int data_to_search_for)
{
	t_stack_node	*iterator;

	iterator = *head;
	while (iterator != NULL)
	{
		if (iterator->data == data_to_search_for)
			return (1);
		iterator = iterator->next;
	}
	return (0);
}

int	rots(t_stack_node **head_b, int data_to_search_for)
{
	int				rots;
	int				rev_rots;
	t_stack_node	*iterator;

	iterator = *head_b;
	rots = 0;
	rev_rots = 0;
	while (iterator->data != data_to_search_for)
	{
		rots++;
		iterator = iterator->next;
	}
	while (iterator != NULL)
	{
		rev_rots++;
		iterator = iterator->next;
	}
	if (rev_rots < rots)
		return (-1 * rev_rots);
	return (rots);
}

void	rotate_stack(int rotations, t_stack_node **head_b)
{
	if (rotations > 0)
	{
		while (rotations > 0)
		{
			rotate_b(head_b);
			rotations--;
		}
	}
	if (rotations < 0)
	{
		rotations = rotations * -1;
		while (rotations > 0)
		{
			rev_rot_b(head_b);
			rotations--;
		}
	}
}

int	abs_val(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	find_fastest(t_stack_node **head_b, int data)
{
	int	fast_access;

	fast_access = 0;
	if (data_is_in(head_b, data) && data_is_in(head_b, data - 1)
		&& data_is_in(head_b, data - 2))
		fast_access = if_all(head_b, data);
	else if (data_is_in(head_b, data) && data_is_in(head_b, data - 1))
		fast_access = if_data_data_1(head_b, data);
	else if (data_is_in(head_b, data) && data_is_in(head_b, data - 2))
		fast_access = if_data_data_2(head_b, data);
	else if (data_is_in(head_b, data - 1) && data_is_in(head_b, data - 2))
		fast_access = if_data_1_data_2(head_b, data);
	else if (data_is_in(head_b, data) || data_is_in(head_b, data - 1)
		|| data_is_in(head_b, data - 2))
		fast_access = if_one_data(head_b, data);
	return (fast_access);
}
