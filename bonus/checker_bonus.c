/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:43:35 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/26 11:58:20 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_stack(t_stack_node *head_b)
{
	t_stack_node	*free_master;

	while (head_b != NULL)
	{
		free_master = head_b;
		head_b = head_b->next;
		free(free_master);
	}
}

int	run_operation(t_stack_node **head_a, t_stack_node **head_b, char *str)
{
	if (ft_strcmp("sa\n", str) == 0)
		return (swap(head_a));
	else if (ft_strcmp("sb\n", str) == 0)
		return (swap(head_b));
	else if (ft_strcmp("ss\n", str) == 0)
		return (swap_ab(head_a, head_b));
	else if (ft_strcmp("ra\n", str) == 0)
		return (rotate(head_a));
	else if (ft_strcmp("rb\n", str) == 0)
		return (rotate(head_b));
	else if (ft_strcmp("rr\n", str) == 0)
		return (rotate_ab(head_a, head_b));
	else if (ft_strcmp("rra\n", str) == 0)
		return (reverse_rotate(head_a));
	else if (ft_strcmp("rrb\n", str) == 0)
		return (reverse_rotate(head_b));
	else if (ft_strcmp("rrr\n", str) == 0)
		return (reverse_rotate_ab(head_a, head_b));
	else if (ft_strcmp("pa\n", str) == 0)
		return (push(head_b, head_a));
	else if (ft_strcmp("pb\n", str) == 0)
		return (push(head_a, head_b));
	else
		return (0);
}

void	check_result(t_stack_node **head_a, t_stack_node **head_b)
{
	if (sorted(head_a) && *head_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	check_sorting(char **args, int argc,
	t_stack_node **head_a, t_stack_node **head_b)
{
	char	*str;

	str = NULL;
	if (error_handling(args, argc))
		return (freiheit (args, *head_a, *head_b, argc));
	*head_a = make_stack_a(argc, args);
	if (*head_a == NULL)
		return (-1);
	str = get_next_line(0);
	while (str != NULL)
	{
		if (!run_operation(head_a, head_b, str))
		{
			free(str);
			freiheit (args, *head_a, *head_b, argc);
			free_stack(*head_b);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(str);
		str = get_next_line(0);
	}
	check_result(head_a, head_b);
	freiheit (args, *head_a, *head_b, argc);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack_node	*head_a;
	t_stack_node	*head_b;
	char			**args;

	head_a = NULL;
	head_b = NULL;
	args = NULL;
	args = parse_args(argv, &argc);
	if (not_valid(argv, args, argc))
		return (write(2, "Error\n", 6));
	if (args != NULL)
		if (check_sorting(args, argc, &head_a, &head_b) == -1)
			return (-1);
	return (0);
}
