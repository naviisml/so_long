/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 13:22:29 by nismail       ########   odam.nl         */
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
	so_long->map->moves = 0;
	so_long->map->initialized = 0;
	so_long->map->exit.x = -1;
	so_long->map->exit.y = -1;
	so_long->map->spawn.x = -1;
	so_long->map->spawn.y = -1;
}

/**
 * The map_initialize_textures() function ..
 */
void	map_initialize_textures(t_server *so_long)
{
	so_long->map->player = sprite_create
		(so_long, "./resources/assets/character-3.xpm");
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
	so_long->map->initialized = 1;
}

void	map_deinitialize_structure(t_server *so_long)
{
	int	i;

	i = so_long->height;
	while (i > 0)
	{
		if (so_long->map->structure[i] != NULL)
			free(so_long->map->structure[i]);
		i--;
	}
	free(so_long->map->structure);
}

/**
 * The map_initialize() function ..
 */
void	map_deinitialize(t_server *so_long)
{
	if (so_long->map->structure)
		map_deinitialize_structure(so_long);
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
