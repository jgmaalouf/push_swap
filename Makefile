# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 20:18:19 by jmaalouf          #+#    #+#              #
#    Updated: 2022/08/26 10:27:27 by jmaalouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc -Wall -Wextra -Werror

SRC = main_and_errorhandling/push_swap.c main_and_errorhandling/make_stack_a.c \
	main_and_errorhandling/helpers.c main_and_errorhandling/error_handling.c \
	sorting_algo/combine_sorts.c sorting_algo/index_stack.c sorting_algo/insertion_find_fastest_rot.c \
	sorting_algo/insertion_sort_to_a_1.c sorting_algo/insertion_sort_to_a_2.c sorting_algo/quicksort_to_b.c sorting_algo/small_value_sort.c \
	ps_operations/push.c ps_operations/reverse_rotate.c ps_operations/swap.c ps_operations/rotate.c \

B_SRC = bonus/checker_bonus.c bonus/make_stack_a_bonus.c bonus/helpers_bonus.c \
	bonus/error_handling_bonus.c bonus/push_bonus.c \
	bonus/reverse_rotate_bonus.c bonus/swap_bonus.c bonus/rotate_bonus.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRC_OBJ = ${SRC:.c=.o}
B_OBJ = ${B_SRC:.c=.o}

all: ${NAME}

${NAME}: ${SRC_OBJ}
	$(MAKE) -C ./ft_printf
	cp ft_printf/libftprintf.a $(NAME)
	ar rcs $@ $^
	${CC} -o push_swap $(SRC) $(NAME)

%.o: %.c
	${CC} -c $^ -o $@

bonus: ${B_OBJ}
	$(MAKE) -C ./ft_printf
	cp ft_printf/libftprintf.a checker.a
	ar rcs checker.a $^
	${CC} -o checker bonus/checker_bonus.c checker.a

clean:
	${MAKE} clean -C ./ft_printf
	rm -f *.o ps_operations/*.o
	rm -f *.o main_and_errorhandling/*.o
	rm -f *.o sorting_algo/*.o
	rm -f *.o bonus/*.o
	rm -f *.o get_next_line/*.o

fclean: clean
	${MAKE} fclean -C ./ft_printf
	rm -f ${NAME}
	rm -f checker.a

pclean:
	rm -f push_swap
	rm -f checker

re: fclean all

.PHONY: all clean fclean re