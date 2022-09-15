/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:37:15 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/05/04 12:14:01 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;

	dlen = ft_strlen(dst);
	i = ft_strlen(dst);
	j = 0;
	if (dlen > dstsize)
		dlen = dstsize;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[j] != '\0')
			dst[i++] = src[j++];
		if (dlen < dstsize)
			dst[i] = '\0';
	}
	return (dlen + ft_strlen(src));
}
