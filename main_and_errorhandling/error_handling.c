/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:46:49 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/25 11:35:46 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long			result;
	long			sign;
	unsigned int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 922337203685477580 && sign != -1)
			return (-1);
		if (result > 922337203685477580 && sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}

int	non_numeric_input(char **args, int wc)
{
	int	i;
	int	j;

	i = 0;
	while (i < wc)
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j] != '\0')
		{
			if (!ft_isdigit(args[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	duplicates(char **args, int wc)
{
	int	i;
	int	j;

	i = 0;
	while (i < wc)
	{
		j = i + 1;
		while (j < wc)
		{
			if (!ft_strcmp(args[i], args[j])
				|| ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	out_of_range(char **args, int wc)
{
	int	i;

	i = 0;
	while (i < wc)
	{
		if (ft_atol(args[i]) > INT_MAX)
			return (1);
		if (ft_atol(args[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	not_valid(char **argv, char **args, int wc)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "") == 0 || ft_strcmp(argv[i], " ") == 0
			|| ft_strcmp(argv[i], "	") == 0)
		{
			i = 0;
			while (i < wc)
			{
				free(args[i]);
				i++;
			}
			free(args);
			return (1);
		}
		i++;
	}
	return (0);
}
