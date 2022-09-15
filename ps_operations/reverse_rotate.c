/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:46:55 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 02:36:14 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*last;
	t_stack_node	*before_last;

	before_last = *head;
	if (*head != NULL && (*head)->next != NULL)
	{
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		last = before_last->next;
		before_last->next = NULL;
		last->next = *head;
		*head = last;
	}
}

void	rev_rot_a(t_stack_node **head_a)
{
	reverse_rotate(head_a);
	ft_printf("%s\n", "rra");
}

void	rev_rot_b(t_stack_node **head_b)
{
	reverse_rotate(head_b);
	ft_printf("%s\n", "rrb");
}

void	reverse_rotate_ab(t_stack_node **head_a, t_stack_node **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	ft_printf("%s\n", "rrr");
}
