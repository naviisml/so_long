/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/01 14:02:00 by nismail       ########   odam.nl         */
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
	so_long->map->tiles = malloc(sizeof(t_map_tiles **));
}

/**
 * The map_deinitialize_structure() function ..
 */
void	map_deinitialize_structure(t_server *so_long)
{
	int	i;
	int	n;

	i = 0;
	n = so_long->height;
	while (i < n)
	{
		free(so_long->map->tiles[i]);
		i++;
	}
	free(so_long->map->tiles);
}

/**
 * The map_initialize() function ..
 */
void	map_deinitialize(t_server *so_long)
{
	if (so_long->map != NULL)
		free(so_long->map);
}
