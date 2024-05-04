/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:04:01 by fatkeski          #+#    #+#             */
/*   Updated: 2023/12/11 15:58:35 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_str(char *s);
int	print_pointer(size_t nbr, int *count);
int	print_int(int nbr, int *count);
int	putnbr_base(unsigned int nb, char *base, int *count);
#endif
