/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:11:06 by fatkeski          #+#    #+#             */
/*   Updated: 2024/05/04 16:44:59 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	calculate_height(t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		print_error("open");
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	close(fd);
	map->height = i;
}

static size_t	ber_line_len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

static void	create_map_vector(t_game *game, int fd, int height)
{
	int		i;
	char	*file_line;
	char	**vector_line;

	vector_line = (char **)malloc(sizeof(char *) * (height + 1));
	if (!vector_line)
		print_error("malloc");
	vector_line[height] = NULL;
	i = 0;
	while (i < height)
	{
		file_line = get_next_line(fd);
		if (!file_line)
			print_error("get_next_line");
		vector_line[i] = ft_substr(file_line, 0, ber_line_len(file_line));
		if ((i == height - 1) && (file_line[ft_strlen(file_line) - 1] == '\n'))
			print_error_message("Error: ending of the map is incorrect\n",
				game);
		free(file_line);
		i++;
	}
	game->map->vector = vector_line;
}

void	create_map(t_game *game)
{
	int	fd;

	fd = open(game->map->path, O_RDONLY);
	if (fd < 0)
		print_error("map open");
	calculate_height(game->map);
	create_map_vector(game, fd, game->map->height);
	close(fd);
}
