/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/25 22:03:35 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The map_initialize() function ..
 */
void	map_initialize(t_server *so_long)
{
	so_long->map = malloc(sizeof(struct s_map));
	so_long->map->fd = 0;
	so_long->map->collectibles = 0;
	so_long->map->spawnpos = NULL;
	so_long->map->structure = NULL;
}

/**
 * The map_initialize() function ..
 */
void	map_deinitialize(t_server *so_long)
{
	if (so_long->map->structure != NULL)
		free(so_long->map->structure);
		// Free so_long->map->structure from back to start
	if (so_long->map != NULL)
		free(so_long->map);
}
