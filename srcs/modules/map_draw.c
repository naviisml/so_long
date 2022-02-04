/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_draw.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/04 17:53:45 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	map_draw(t_server *so_long)
{
	int	x;
	int	y;

	x = 0;
	while (so_long->map->structure[x] != NULL)
	{
		y = 0;
		while (so_long->map->structure[x][y] != '\0')
		{
			y++;
		}
		x++;
	}
}