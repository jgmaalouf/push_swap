/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_value_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:57:40 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/15 00:30:51 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

void	rotate_stack_a(int rotations, t_stack_node **head_a)
{
	if (rotations > 0)
	{
		while (rotations > 0)
		{
			rotate_a(head_a);
			rotations--;
		}
	}
	if (rotations < 0)
	{
		rotations = rotations * -1;
		while (rotations > 0)
		{
			rev_rot_a(head_a);
			rotations--;
		}
	}
}

void	sort_3_a(t_stack_node **head_a)
{
	if ((*head_a)->data > (*head_a)->next->data
		&& (*head_a)->next->data > (*head_a)->next->next->data
		&& (*head_a)->next->next->next == NULL)
	{
		swap_a(head_a);
		rev_rot_a(head_a);
	}
	else if ((*head_a)->data < (*head_a)->next->data
		&& (*head_a)->data > (*head_a)->next->next->data)
	{
		rotate_a(head_a);
		swap_a(head_a);
		rev_rot_a(head_a);
		swap_a(head_a);
	}
	else if ((*head_a)->data < (*head_a)->next->data
		&& (*head_a)->next->data > (*head_a)->next->next->data)
	{
		rotate_a(head_a);
		swap_a(head_a);
		rev_rot_a(head_a);
	}
	else if ((*head_a)->data > (*head_a)->next->data
		&& (*head_a)->data < (*head_a)->next->next->data)
		swap_a(head_a);
}

void	sort_3(t_stack_node **head_a)
{
	if (((*head_a)->data < (*head_a)->next->data
			&& (*head_a)->data > (*head_a)->next->next->data)
		|| ((*head_a)->data < (*head_a)->next->data
			&& (*head_a)->next->data > (*head_a)->next->next->data)
		|| ((*head_a)->data > (*head_a)->next->data
			&& (*head_a)->data < (*head_a)->next->next->data))
		sort_3_a(head_a);
	else if ((*head_a)->data > (*head_a)->next->data
		&& (*head_a)->next->data > (*head_a)->next->next->data)
	{
		swap_a(head_a);
		rotate_a(head_a);
		swap_a(head_a);
		rev_rot_a(head_a);
		swap_a(head_a);
	}
	else if ((*head_a)->data > (*head_a)->next->data
		&& (*head_a)->data > (*head_a)->next->next->data)
	{
		swap_a(head_a);
		rotate_a(head_a);
		swap_a(head_a);
		rev_rot_a(head_a);
	}
}

void	sort_3_optimized(t_stack_node **head_a)
{
	if ((*head_a)->data < (*head_a)->next->data
		&& (*head_a)->data > (*head_a)->next->next->data)
		rev_rot_a(head_a);
	else if ((*head_a)->data < (*head_a)->next->data
		&& (*head_a)->next->data > (*head_a)->next->next->data)
	{
		rotate_a(head_a);
		swap_a(head_a);
		rev_rot_a(head_a);
	}
	else if ((*head_a)->data > (*head_a)->next->data
		&& (*head_a)->data < (*head_a)->next->next->data)
		swap_a(head_a);
	else if ((*head_a)->data > (*head_a)->next->data
		&& (*head_a)->next->data > (*head_a)->next->next->data)
	{
		rotate_a(head_a);
		swap_a(head_a);
	}
	else if ((*head_a)->data > (*head_a)->next->data
		&& (*head_a)->data > (*head_a)->next->next->data)
		rotate_a(head_a);
}
