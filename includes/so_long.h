/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:13:42 by fatkeski          #+#    #+#             */
/*   Updated: 2024/05/04 15:19:04 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define ESC 53
# define A 0
# define S 1
# define D 2
# define W 13
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

# define CROSS 17
# define KEY_PRESS 02

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_exit
{
	int			x;
	int			y;
}				t_exit;

typedef struct s_map
{
	char		**vector;
	char		*path;
	int			width;
	int			height;
}				t_map;

typedef struct s_img
{
	void		*floor;
	void		*wall;
	void		*collectible;
	void		*player;
	void		*exit;
}				t_img;

typedef struct s_game
{
	t_map		*map;
	void		*mlx;
	void		*mlx_window;
	int			collectible_count;
	int			move_count;
	t_img		img_ptr;
	t_player	player;
	t_exit		exit;
}				t_game;

typedef struct s_count
{
	int			exit;
	int			player;
	int			collectible;
}				t_count;

void			ber_file_check(char *file_name, t_game *game);
void			create_map(t_game *game);
void			print_error(char *error_message);
void			print_error_message(char *error_message, t_game *game);
void			map_format_check(t_game *game);
void			map_valid_path_check(t_game *game);
void			create_game_interface(t_game *game);
void			put_image_to_window(t_game *game);
int				key_handler(int key_code, t_game *game);
int				exit_game(t_game *game);
void			free_map(char **map);

#endif
