/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/28 12:05:45 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	debug_print_map(t_server *so_long);

/**
 * so_long ...
 */
int	main(int argc, char **argv)
{
	t_server	so_long;

	if (argc != 2)
		return (game_error(&so_long, "No map specified."));
	server_initialize(&so_long);
	client_initialize(&so_long);
	map_initialize(&so_long);
	if (map_check(&so_long, argv[1]) != 1)
		return (game_error(&so_long, "No map specified."));
	if (map_parse(&so_long) != 1)
		return (game_error(&so_long, "No memory available."));
	debug_print_map(&so_long);
	game_start(&so_long);
	mlx_hook(so_long.window, 2, (1L << 17), events_loop, &so_long);
	mlx_loop(so_long.mlx);
}