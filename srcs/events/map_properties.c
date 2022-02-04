/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_properties.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/04 18:14:35 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The set_map_spawn() function ..
 */
int	set_map_spawn(t_server *so_long, char c, int x, int y)
{
	(void)c;
	so_long->map->spawn.x = x;
	so_long->map->spawn.y = y;
	return (1);
}

/**
 * The set_map_spawn() function ..
 */
int	set_map_exit(t_server *so_long, char c, int x, int y)
{
	(void)c;
	so_long->map->exit.x = x;
	so_long->map->exit.y = y;
	return (1);
}

/**
 * The add_map_collectible() function ..
 */
int	add_map_collectible(t_server *so_long, char c, int x, int y)
{
	(void)x;
	(void)y;
	(void)c;
	so_long->map->collectibles += 1;
	return (1);
}
