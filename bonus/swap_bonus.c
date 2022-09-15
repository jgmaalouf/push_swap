/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:44:25 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 15:54:45 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	swap(t_stack_node **head)
{
	t_stack_node	*first_node;

	first_node = *head;
	if (*head != NULL && (*head)->next != NULL)
	{
		*head = (*head)->next;
		first_node->next = first_node->next->next;
		(*head)->next = first_node;
	}
	return (1);
}

int	swap_ab(t_stack_node **head_a, t_stack_node **head_b)
{
	swap(head_a);
	swap(head_b);
	return (1);
}
