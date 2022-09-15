/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:46:49 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/08/04 19:18:38 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i++;
	}
	return (0);
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
			if (!ft_strcmp(args[i], args[j]))
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
