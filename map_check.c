/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:11:00 by fatkeski          #+#    #+#             */
/*   Updated: 2024/05/04 17:41:46 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	ber_file_check(char *file_name, t_game *game)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 4 || ft_strncmp(".ber", &(file_name[len - 4]), 4) != 0)
		print_error_message("Error: not ber file\n", game);
}

static void	wall_check(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->width)
	{
		if ((game->map->vector[0][i] == WALL)
			&& (game->map->vector[game->map->height - 1][i] == WALL))
			i++;
		else
			print_error_message("Error: map up-low frame error\n", game);
	}
	i = 1;
	while (i < game->map->height - 1)
	{
		if (game->map->vector[i][0] == WALL
			&& game->map->vector[i][game->map->width - 1] == WALL)
			i++;
		else
			print_error_message("Error: map side frame error\n", game);
	}
}

static void	valid_component_check(t_game *game, int i, int j, t_count *count)
{
	char	*arr;

	arr = game->map->vector[i];
	while (j < game->map->width)
	{
		if ((arr[j] != WALL) && (arr[j] != FLOOR) && (arr[j] != PLAYER)
			&& (arr[j] != COLLECTIBLE) && (arr[j] != EXIT))
			print_error_message("Error: invalid component\n", game);
		if (arr[j] == PLAYER)
		{
			(count->player)++;
			(game->player).x = j;
			(game->player).y = i;
		}
		else if (arr[j] == COLLECTIBLE)
			(count->collectible)++;
		else if (arr[j] == EXIT)
		{
			(count->exit)++;
			(game->exit).x = j;
			(game->exit).y = i;
		}
		j++;
	}
}

static void	map_component_check(t_game *game)
{
	int				i;
	static t_count	count;

	i = 0;
	while (i < game->map->height)
	{
		valid_component_check(game, i, 0, &count);
		i++;
	}
	if ((count.collectible < 1) || (count.exit != 1) || (count.player != 1))
		print_error_message("Error: number of components is incorrect\n", game);
	game->collectible_count = count.collectible;
}

void	map_format_check(t_game *game)
{
	int	i;
	int	line_len;
	int	tmp_len;

	if (game->map->vector[0] == NULL)
		print_error_message("Error: empty map\n", game);
	i = 0;
	line_len = ft_strlen(game->map->vector[0]);
	while (i < game->map->height)
	{
		tmp_len = ft_strlen(game->map->vector[i]);
		if (tmp_len == 0)
			print_error_message("Error: map is incomplete\n", game);
		if (line_len != tmp_len)
			print_error_message("Error: map is not rectangular\n", game);
		i++;
	}
	game->map->width = line_len;
	wall_check(game);
	map_component_check(game);
	map_valid_path_check(game);
}
