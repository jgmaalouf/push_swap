/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:47:42 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/25 11:35:58 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack_list
{
	int					data;
	int					index;
	struct s_stack_list	*next;
}						t_stack_node;

// push_swap syntax functions:
void			swap(t_stack_node **head);
void			swap_a(t_stack_node **head_a);
void			swap_b(t_stack_node **head_b);
void			swap_ab(t_stack_node **head_a, t_stack_node **head_b);

void			push(t_stack_node **head_from, t_stack_node **head_to);
void			push_a(t_stack_node **head_b, t_stack_node **head_a);
void			push_b(t_stack_node **head_a, t_stack_node **head_b);

void			rotate(t_stack_node **head);
void			rotate_a(t_stack_node **head_a);
void			rotate_b(t_stack_node **head_b);
void			rotate_ab(t_stack_node **head_a, t_stack_node **head_b);

void			reverse_rotate(t_stack_node **head);
void			rev_rot_a(t_stack_node **head_a);
void			rev_rot_b(t_stack_node **head_b);
void			reverse_rotate_ab(t_stack_node **head_a, t_stack_node **head_b);

// Main functions
t_stack_node	*make_stack_a(int node_count, char **node_content);
void			combine_sorts(t_stack_node **head_a,
					t_stack_node **head_b, int element_count);

// Helper Functions
void			store_in_better_args(char **split_res, char **better_args);
void			freiheit(char **args, t_stack_node *head_a, int argc);
int				abs_val(int num);
int				data_is_in(t_stack_node **head, int data_to_search_for);
int				sorted(t_stack_node **head_a);
int				ft_strcmp(const char *str1, const char *str2);

// Error Handlers
int				error_handling(char **args, int wc);
int				non_numeric_input(char **args, int wc);
int				duplicates(char **args, int wc);
int				out_of_range(char **args, int wc);
int				not_valid(char **argv, char **args, int wc);

// Indexing Functions
void			reset_index(t_stack_node **head);
void			set_index(int min, t_stack_node **head, int index);
void			index_stack(t_stack_node **head, int max_index);
void			make_data_increment_1(t_stack_node **head_a);

// Sorting Functions
int				find_fastest(t_stack_node **head_b, int data);
int				if_data_1_data_2(t_stack_node **head_b, int data);
int				if_one_data(t_stack_node **head_b, int data);
int				if_all(t_stack_node **head_b, int data);
int				if_data_data_1(t_stack_node **head_b, int data);
int				if_data_data_2(t_stack_node **head_b, int data);
void			send_3_num(t_stack_node **head_a,
					t_stack_node **head_b, int data);
void			rotate_stack_a(int rotations, t_stack_node **head_a);
int				rots(t_stack_node **head_b, int data_to_search_for);
void			sort_3(t_stack_node **head_a);
void			sort_3_optimized(t_stack_node **head_a);
void			quicksort_to_b(t_stack_node **head_a,
					t_stack_node **head_b, int max_index);
void			rotate_stack(int rotations, t_stack_node **head_b);

#endif
