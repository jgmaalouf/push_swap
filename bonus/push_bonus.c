/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:45:41 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 15:55:10 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	push(t_stack_node **head_from, t_stack_node **head_to)
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
	return (1);
}
