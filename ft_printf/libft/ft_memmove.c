/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:18:18 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/05/04 08:50:24 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_char;
	char	*src_char;

	dst_char = (char *) dst;
	src_char = (char *) src;
	if (src_char < dst_char)
	{
		while (len-- > 0)
			dst_char[len] = src_char[len];
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
