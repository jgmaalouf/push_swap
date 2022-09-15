/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:14:16 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/26 10:54:54 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../ft_printf/libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <limits.h>

typedef struct s_stack_list
{
	int					data;
	int					index;
	struct s_stack_list	*next;
}						t_stack_node;

// push_swap syntax functions:
int				swap(t_stack_node **head);
int				swap_ab(t_stack_node **head_a, t_stack_node **head_b);

int				push(t_stack_node **head_from, t_stack_node **head_to);

int				rotate(t_stack_node **head);
int				rotate_ab(t_stack_node **head_a, t_stack_node **head_b);

int				reverse_rotate(t_stack_node **head);
int				reverse_rotate_ab(t_stack_node **head_a, t_stack_node **head_b);

// Main functions
t_stack_node	*make_stack_a(int node_count, char **node_content);

// Helper Functions
void			store_in_better_args(char **split_res, char **better_args);
int				freiheit(char **args, t_stack_node *head_a,
					t_stack_node *head_b, int argc);
int				abs_val(int num);
int				data_is_in(t_stack_node **head, int data_to_search_for);
char			**parse_args(char **argv, int *wc);
int				ft_strcmp(const char *str1, const char *str2);
int				sorted(t_stack_node **head_a);
int				not_valid(char **argv, char **args, int wc);

// Error Handlers
int				error_handling(char **args, int wc);
int				non_numeric_input(char **args, int wc);
int				duplicates(char **args, int wc);
int				out_of_range(char **args, int wc);

#endif