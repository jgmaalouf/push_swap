/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:46:19 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 03:13:30 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

void	rotate(t_stack_node **head)
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
}

void	rotate_a(t_stack_node **head_a)
{
	rotate(head_a);
	ft_printf("%s\n", "ra");
}

void	rotate_b(t_stack_node **head_b)
{
	rotate(head_b);
	ft_printf("%s\n", "rb");
}

void	rotate_ab(t_stack_node **head_a, t_stack_node **head_b)
{
	rotate(head_a);
	rotate(head_b);
	ft_printf("%s\n", "rr");
}
