/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:10:29 by fatkeski          #+#    #+#             */
/*   Updated: 2024/05/04 16:05:57 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (map == NULL)
		exit(0);
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_error_message(char *error_message, t_game *game)
{
	ft_printf(error_message);
	ft_printf("\n");
	free_map(game->map->vector);
	exit(EXIT_FAILURE);
}

void	print_error(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}
