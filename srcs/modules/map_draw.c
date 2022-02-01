/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/01 11:45:55 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	map_draw(t_server *so_long)
{
	t_sprite	*image;
	int	x;
	int	y;

	x = 0;
	image = malloc(sizeof(t_sprite));
	while (so_long->map->structure[x] != NULL)
	{
		y = 0;
		while (so_long->map->structure[x][y] != '\0')
		{
			if (so_long->map->structure[x][y] == '1')
				image->path = "./resources/assets/tile0.png";
			else
				image->path = "./resources/assets/tile1.png";
			image->width = 32;
			image->height = 32;
			image->x = (x * 32);
			image->y = (y * 32);
			draw_sprite(so_long, image);
			y++;
		}
		x++;
	}
	free(image);
}
