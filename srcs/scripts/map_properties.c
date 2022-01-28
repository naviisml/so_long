/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_properties.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/28 13:02:25 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The set_map_spawn() function ..
 */
void	set_map_spawn(t_server *so_long, char c, int x, int y)
{
	(void)so_long;
	(void)x;
	(void)y;
	
	ft_putchar_fd(c, 0);
}

/**
 * The set_map_spawn() function ..
 */
void	set_map_exit(t_server *so_long, char c, int x, int y)
{
	(void)so_long;
	(void)c;
	so_long->map->spawnpos = malloc(2);
	so_long->map->spawnpos[0] = x;
	so_long->map->spawnpos[1] = y;
	ft_putchar_fd(c, 0);
}

void	add_map_collectible(t_server *so_long, char c, int x, int y)
{
	(void)x;
	(void)y;
	(void)c;
	so_long->map->collectibles += 1;
}