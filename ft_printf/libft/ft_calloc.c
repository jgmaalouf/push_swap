/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:40:31 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/05/05 11:24:32 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size_in_bytes;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	size_in_bytes = count * size;
	ptr = NULL;
	ptr = malloc(size_in_bytes);
	if (ptr != NULL)
		ft_bzero(ptr, size_in_bytes);
	return (ptr);
}
