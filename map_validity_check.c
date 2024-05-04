/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:11:12 by fatkeski          #+#    #+#             */
/*   Updated: 2024/05/04 17:42:05 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	flood_fill(int i, int j, char **map_vector, t_map *map)
{
	if ((i < 0) || (i > map->height - 1) || (j < 0) || (j > map->width - 1))
		return ;
	if (map_vector[i][j] != '1' && map_vector[i][j] != 'F')
	{
		map_vector[i][j] = 'F';
		flood_fill(i - 1, j, map_vector, map);
		flood_fill(i + 1, j, map_vector, map);
		flood_fill(i, j - 1, map_vector, map);
		flood_fill(i, j + 1, map_vector, map);
	}
}

static char	**create_copy_map_vector(t_map *map)
{
	char	**vector;
	int		i;

	vector = (char **)malloc((sizeof(char *) * map->height) + 1);
	if (!vector)
		print_error("copy_vector:");
	vector[map->height] = NULL;
	i = 0;
	while (i < map->height)
	{
		vector[i] = ft_strdup(map->vector[i]);
		i++;
	}
	return (vector);
}

void	map_valid_path_check(t_game *game)
{
	int		i;
	int		j;
	char	**copy_vector;

	copy_vector = create_copy_map_vector(game->map);
	flood_fill((game->player).y, (game->player).x, copy_vector, game->map);
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if ((copy_vector[i][j] == EXIT)
				|| (copy_vector[i][j] == COLLECTIBLE))
			{
				print_error_message("Error: map is not validity\n", game);
				free_map(copy_vector);
			}
			j++;
		}
		i++;
	}
	free_map(copy_vector);
}
