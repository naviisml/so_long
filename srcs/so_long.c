/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/20 14:16:25 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The initialize() function ..
 */
static void	initialize(s_server *so_long, char *map)
{
	so_long->mlx = NULL;
	so_long->window = NULL;
	so_long->client = malloc(sizeof(struct t_client));
	so_long->client->x = 0;
	so_long->client->y = 0;
	so_long->client->collected = 0;
	so_long->map = malloc(sizeof(struct t_map));
	so_long->map->file = map;
	so_long->map->fd = 0;
	so_long->map->collectibles = 0;
	so_long->map->spawnpos = NULL;
	so_long->map->structure = NULL;
}

/**
 * so_long ...
 */
int	main(int argc, char **argv)
{
	s_server	so_long;
	char		*map;

	if (argc != 2)
		return(window_err(&so_long, "No map"));
	map = argv[1];
	initialize(&so_long, map);
	window_create(&so_long);
	mlx_hook(so_long.window, 2, (1L << 0), window_destroy, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}