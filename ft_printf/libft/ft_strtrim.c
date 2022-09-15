/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaalouf <jmaalouf@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:43:10 by jmaalouf          #+#    #+#             */
/*   Updated: 2022/05/04 13:31:54 by jmaalouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
	{	
		i++;
		if (s1[i] == '\0')
			return (ft_strdup(""));
	}
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j]) && j != 0)
		j--;
	return (ft_substr (s1, i, (j - i) + 1));
}
