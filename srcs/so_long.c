/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 14:32:41 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The render() function ...
 */
int	render(t_server *so_long)
{
	map_draw(so_long);
	sprite_paint(so_long, &so_long->map->player, so_long->map->player.size.x, so_long->map->player.size.y);
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->data.pointer, 0, 0);
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
	map_initialize(&so_long);
	if (map_open(&so_long, argv[1]) != 1)
		return (0);
	if (map_parse(&so_long) != 1)
		return (0);
	if (map_check(&so_long) != 1)
		return (0);
	game_start(&so_long);
	map_load(&so_long);
	mlx_hook(so_long.window, 2, (1L << 0), events_loop, &so_long);
	mlx_hook(so_long.window, 17, (1L << 17), game_destroy, &so_long);
	mlx_loop_hook(so_long.mlx, render, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
