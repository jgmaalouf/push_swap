/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 10:53:10 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/06/07 16:48:39 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_digits(long long n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	res_if_neg(int len, long nb, char *char_int)
{
	int	i;

	char_int[0] = '-';
	i = 1;
	nb = nb * -1;
	while (len > 0)
	{
		char_int[len] = (nb % 10) + '0';
		nb = nb - (nb % 10);
		nb = nb / 10;
		i++;
		len--;
	}
	return (i);
}

static int	res_if_pos(int len, long nb, char *char_int)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		char_int[len - 1] = (nb % 10) + '0';
		nb = nb - (nb % 10);
		nb = nb / 10;
		i++;
		len--;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*char_int;
	int		len;
	long	nb;

	nb = n;
	len = n_digits(n);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		char_int = (char *)malloc(sizeof(char) * (len + 2));
		if (char_int == NULL)
			return (NULL);
		char_int[res_if_neg(len, nb, char_int)] = '\0';
	}
	else
	{
		char_int = (char *)malloc(sizeof(char) * (len + 1));
		if (char_int == NULL)
			return (NULL);
		char_int[res_if_pos(len, nb, char_int)] = '\0';
	}
	return (char_int);
}
