/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 21:10:54 by fatkeski          #+#    #+#             */
/*   Updated: 2024/05/04 18:11:16 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int ac, char **av)
{
	static t_game	game;
	static t_map	map;

	game.map = &map;
	if (ac == 2)
	{
		ber_file_check(av[1], &game);
		(game.map)->path = av[1];
		create_map(&game);
		map_format_check(&game);
		if ((game.map)->height > 20 || (game.map)->width > 40)
			print_error_message("Error: window size extends from screen\n",
				&game);
		create_game_interface(&game);
		free_map((game.map)->vector);
	}
	else
		ft_printf("Error: 2 arguments must be entered!\n");
	return (0);
}
