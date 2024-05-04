/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:44:58 by fatkeski          #+#    #+#             */
/*   Updated: 2023/10/30 20:45:25 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;

	if (s == 0)
		return (0);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if ((slen - start) < len)
		len = slen - start;
	sub = (char *)malloc(len + 1);
	if (sub == 0)
		return (0);
	ft_memcpy(sub, &s[start], len);
	sub[len] = '\0';
	return (sub);
}
