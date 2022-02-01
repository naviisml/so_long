/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/01 13:55:27 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <get_next_line.h>

/**
 * The g_map_tiles[] struct ..
 */
t_map_tiles	g_map_tiles[] = {
{'0', example_function},
{'1', example_function},
{'C', add_map_collectible},
{'E', set_map_exit},
{'P', set_map_spawn}
};

/**
 * The map_parse_tile() function ..
 */
static int	map_parse_tile(t_server *so_long, char c, int x, int y)
{
	int	i;

	i = 0;
	while (g_map_tiles[i].callback != NULL)
	{
		if (g_map_tiles[i].c == c)
			return (g_map_tiles[i].callback(so_long, c, x, y));
		i++;
	}
	return (game_error(so_long, ERROR_TILES));
}

/**
 * The map_parse_line() function ..
 */
static int	map_parse_line(t_server *so_long, char *line, int x)
{
	int	y;

	y = 0;
	while (line[y] != '\0' && line[y] != '\n')
	{
		map_parse_tile(so_long, line[y], x, y);
		y++;
	}
	return (1);
}

/**
 * The map_parse() function ..
 */
int	map_parse(t_server *so_long)
{
	char	*line;
	int		x;

	x = 0;
	line = get_next_line(so_long->map->fd);
	so_long->width = ft_strlen(line);
	while (line != NULL)
	{
		if (map_parse_line(so_long, line, x) == 0)
			return (0);
		free(line);
		line = get_next_line(so_long->map->fd);
		x++;
	}
	so_long->height = x;
	close(so_long->map->fd);
	return (1);
}
