/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:20:25 by fatkeski          #+#    #+#             */
/*   Updated: 2023/12/11 15:58:20 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_str(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (s && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_pointer(size_t nbr, int *count)
{
	if (nbr >= 16)
	{
		print_pointer(nbr / 16, count);
		print_pointer(nbr % 16, count);
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[nbr], 1);
		(*count)++;
	}
	return (*count);
}

int	print_int(int nbr, int *count)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		(*count)++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		print_int(nb / 10, count);
		print_int(nb % 10, count);
	}
	else
	{
		ft_putchar_fd(nb + 48, 1);
		(*count)++;
	}
	return (*count);
}

int	putnbr_base(unsigned int nb, char *base, int *count)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
	{
		putnbr_base(nb / base_len, base, count);
		putnbr_base(nb % base_len, base, count);
	}
	else
	{
		ft_putchar_fd(base[nb], 1);
		(*count)++;
	}
	return (*count);
}
