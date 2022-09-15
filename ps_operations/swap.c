/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:44:25 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 03:13:39 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

void	swap(t_stack_node **head)
{
	t_stack_node	*first_node;

	first_node = *head;
	if (*head != NULL && (*head)->next != NULL)
	{
		*head = (*head)->next;
		first_node->next = first_node->next->next;
		(*head)->next = first_node;
	}
}

void	swap_a(t_stack_node **head_a)
{
	swap(head_a);
	ft_printf("%s\n", "sa");
}

void	swap_b(t_stack_node **head_b)
{
	swap(head_b);
	ft_printf("%s\n", "sb");
}

void	swap_ab(t_stack_node **head_a, t_stack_node **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_printf("%s\n", "ss");
}
