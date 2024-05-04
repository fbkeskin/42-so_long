/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:19:59 by fatkeski          #+#    #+#             */
/*   Updated: 2023/12/11 15:59:56 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_transform(va_list ap, char c, size_t *i)
{
	int	result;

	result = 0;
	if (c == 'c')
		result = print_char(va_arg(ap, int));
	else if (c == 's')
		result = print_str(va_arg(ap, char *));
	else if (c == 'p')
		result = print_str("0x") + print_pointer((size_t)va_arg(ap, void *),
				&result);
	else if (c == 'd' || c == 'i')
		print_int(va_arg(ap, int), &result);
	else if (c == 'u')
		putnbr_base(va_arg(ap, unsigned int), "0123456789", &result);
	else if (c == 'x')
		putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", &result);
	else if (c == 'X')
		putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", &result);
	else if (c == '%')
		result = print_char('%');
	else
		return ((*i)--);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	size_t	i;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i] != '\0' && i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			i++;
			len += format_transform(ap, str[i], &i);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
