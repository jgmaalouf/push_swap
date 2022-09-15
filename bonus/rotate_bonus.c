/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:46:19 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 15:54:56 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	rotate(t_stack_node **head)
{
	t_stack_node	*tmp;

	tmp = *head;
	if (*head != NULL && (*head)->next != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = *head;
		*head = (*head)->next;
		tmp->next->next = NULL;
	}
	return (1);
}

int	rotate_ab(t_stack_node **head_a, t_stack_node **head_b)
{
	rotate(head_a);
	rotate(head_b);
	return (1);
}
