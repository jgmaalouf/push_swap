/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:45:41 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 02:35:52 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_and_errorhandling/push_swap.h"

void	push(t_stack_node **head_from, t_stack_node **head_to)
{
	t_stack_node	*tmp1;
	t_stack_node	*tmp2;

	tmp1 = *head_from;
	tmp2 = *head_to;
	if (*head_from != NULL)
	{
		*head_from = (*head_from)->next;
		*head_to = tmp1;
		(*head_to)->next = tmp2;
	}
}

void	push_a(t_stack_node **head_b, t_stack_node **head_a)
{
	push(head_b, head_a);
	ft_printf("%s\n", "pa");
}

void	push_b(t_stack_node **head_a, t_stack_node **head_b)
{
	push(head_a, head_b);
	ft_printf("%s\n", "pb");
}
