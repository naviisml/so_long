/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/01 13:38:54 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	debug_print_map(t_server *so_long);

static int	render(t_server *so_long)
{
	map_draw(so_long);
	client_draw(so_long);
	return (0);
}

/**
 * so_long ...
 */
int	main(int argc, char **argv)
{
	t_server	so_long;

	if (argc != 2)
		return (game_error(&so_long, ERROR_NO_ARGS));
	server_initialize(&so_long);
	client_initialize(&so_long);
	map_initialize(&so_long);
	if (map_open(&so_long, argv[1]) != 1)
		return (0);
	if (map_parse(&so_long) != 1)
		return (0);
	if (map_check(&so_long) != 1)
		return (0);
	game_start(&so_long);
	debug_print_map(&so_long);
	mlx_hook(so_long.window, 2, (1L << 17), events_loop, &so_long);
	mlx_loop_hook(so_long.mlx, render, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
