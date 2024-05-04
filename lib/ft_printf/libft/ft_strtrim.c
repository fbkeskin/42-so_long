/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:44:54 by fatkeski          #+#    #+#             */
/*   Updated: 2023/10/30 20:44:55 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len_s1;
	char	*new_arr;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	len_s1 = ft_strlen(s1) - 1;
	while (len_s1 >= 0)
	{
		if (ft_strchr(set, s1[len_s1]) == 0)
			break ;
		len_s1--;
	}
	new_arr = ft_substr(s1, i, (len_s1 - i + 1));
	return (new_arr);
}
