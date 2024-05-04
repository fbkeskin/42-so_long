/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:44:41 by fatkeski          #+#    #+#             */
/*   Updated: 2023/10/30 20:48:00 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while ((i < len) && (haystack[i] != '\0'))
	{
		if ((ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0) && (i
				+ ft_strlen(needle) <= len))
			return (&((char *)haystack)[i]);
		i++;
	}
	return (0);
}
