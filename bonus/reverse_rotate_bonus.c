/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:46:55 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 15:55:05 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	reverse_rotate(t_stack_node **head)
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
	return (1);
}

int	reverse_rotate_ab(t_stack_node **head_a, t_stack_node **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	return (1);
}
