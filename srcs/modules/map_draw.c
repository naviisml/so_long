/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 12:00:54 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The map_tile() function ..
 */
static void	map_tile(t_server *so_long, int x, int y)
{
	int	res;

	res = (so_long->width + so_long->height + x + y * (y / 32) % 36) % 5;
	if (res == 4)
		sprite_paint(so_long, &so_long->map->tile2, x, y);
	else
		sprite_paint(so_long, &so_long->map->tile1, x, y);
}

/**
 * The map_draw() function ..
 */
void	map_draw(t_server *so_long)
{
	int			x;
	int			y;

	x = 0;
	while (so_long->map->structure[x] != NULL)
	{
		y = 0;
		while (so_long->map->structure[x][y] != '\0')
		{
			if (so_long->map->structure[x][y] == '1')
				sprite_paint(so_long, &so_long->map->wall, (y * 32), (x * 32));
			else
				map_tile(so_long, (y * 32), (x * 32));
			if (so_long->map->structure[x][y] == 'C')
				sprite_paint(so_long, &so_long->map->coin, (y * 32), (x * 32));
			if (so_long->map->structure[x][y] == 'E')
				sprite_paint(so_long, &so_long->map->door, (y * 32), (x * 32));
			y++;
		}
		x++;
	}
}
