/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 13:03:48 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The map_initialize() function ..
 */
void	map_initialize(t_server *so_long)
{
	so_long->map = malloc(sizeof(struct s_map));
	so_long->map->collectibles = 0;
}

/**
 * The map_initialize_textures() function ..
 */
void	map_initialize_textures(t_server *so_long)
{
	so_long->map->player = sprite_create
		(so_long, "./resources/assets/character.xpm");
	so_long->map->player.size.x = so_long->map->spawn.x;
	so_long->map->player.size.y = so_long->map->spawn.y;
	so_long->map->wall = sprite_create
		(so_long, "./resources/assets/wall.xpm");
	so_long->map->tile1 = sprite_create
		(so_long, "./resources/assets/tile1.xpm");
	so_long->map->tile2 = sprite_create
		(so_long, "./resources/assets/tile2.xpm");
	so_long->map->coin = sprite_create
		(so_long, "./resources/assets/collectible.xpm");
	so_long->map->door = sprite_create
		(so_long, "./resources/assets/door-locked.xpm");
}

/**
 * The map_initialize() function ..
 */
void	map_deinitialize(t_server *so_long)
{
	if (so_long->map != NULL)
		free(so_long->map);
}

/**
 * The map_deinitialize_textures() function ..
 */
void	map_deinitialize_textures(t_server *so_long)
{
	if (so_long->map->player.pointer)
		mlx_destroy_image(so_long->mlx, so_long->map->player.pointer);
	if (so_long->map->wall.pointer)
		mlx_destroy_image(so_long->mlx, so_long->map->wall.pointer);
	if (so_long->map->tile1.pointer)
		mlx_destroy_image(so_long->mlx, so_long->map->tile1.pointer);
	if (so_long->map->tile2.pointer)
		mlx_destroy_image(so_long->mlx, so_long->map->tile2.pointer);
	if (so_long->map->coin.pointer)
		mlx_destroy_image(so_long->mlx, so_long->map->coin.pointer);
	if (so_long->map->door.pointer)
		mlx_destroy_image(so_long->mlx, so_long->map->door.pointer);
}
