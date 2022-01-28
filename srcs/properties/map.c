/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/28 13:20:50 by nismail       ########   odam.nl         */
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
	so_long->map->spawn = NULL;
	so_long->map->exit = NULL;
	so_long->map->structure = NULL;
}

/**
 * The map_deinitialize_structure() function ..
 */
static void	map_deinitialize_structure(t_server *so_long)
{
	int	i;
	int	n;

	i = 0;
	n = so_long->height;
	while (i < n)
	{
		free(so_long->map->structure[i]);
		i++;
	}
	free(so_long->map->structure);
}

/**
 * The map_initialize() function ..
 */
void	map_deinitialize(t_server *so_long)
{
	if (so_long->map->spawn)
		free(so_long->map->spawn);
	if (so_long->map->exit)
		free(so_long->map->exit);
	if (so_long->map->structure != NULL)
		map_deinitialize_structure(so_long);
	if (so_long->map != NULL)
		free(so_long->map);
}
