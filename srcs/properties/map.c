/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/23 22:34:10 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The initialize_map() function ..
 */
void	initialize_map(s_server *so_long, char *map)
{
	so_long->map = malloc(sizeof(struct t_map));
	so_long->map->file = map;
	so_long->map->fd = 0;
	so_long->map->collectibles = 0;
	so_long->map->spawnpos = NULL;
	so_long->map->structure = NULL;
	map_open(so_long);
}
