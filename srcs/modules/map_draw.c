/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 14:29:25 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
				sprite_paint(so_long, &so_long->map->tile0, (y * 32), (x * 32));
			else
				sprite_paint(so_long, &so_long->map->tile1, (y * 32), (x * 32));
			if (so_long->map->structure[x][y] == 'C')
				sprite_paint(so_long, &so_long->map->collectible, (y * 32), (x * 32));
			y++;
		}
		x++;
	}
}

void	map_load(t_server *so_long)
{
	so_long->map->player = sprite_create(so_long, "./resources/assets/character.xpm");
	so_long->map->player.size.x = (so_long->map->spawn.x * 32);
	so_long->map->player.size.y = (so_long->map->spawn.y * 32);
	so_long->map->tile0 = sprite_create(so_long, "./resources/assets/tile0.xpm");
	so_long->map->tile1 = sprite_create(so_long, "./resources/assets/tile1.xpm");
	so_long->map->collectible = sprite_create(so_long, "./resources/assets/fish1.xpm");
}
