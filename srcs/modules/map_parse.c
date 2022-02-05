/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/04 17:42:15 by nismail       ########   odam.nl         */
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
	int	len;

	len = ft_strlen(line);
	y = 0;
	so_long->map->structure[x] = (char *)malloc(len + 1);
	if (!so_long->map->structure[x])
		return (game_error(so_long, ERROR_NO_MEMORY));
	while (line[y] != '\0' && line[y] != '\n')
	{
		so_long->map->structure[x][y] = line[y];
		map_parse_tile(so_long, line[y], x, y);
		y++;
	}
	so_long->map->structure[x][y] = '\0';
	so_long->width = len;
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
	so_long->map->structure = (char **)malloc(sizeof(char **) * 100);
	if (!so_long->map->structure)
		return (game_error(so_long, ERROR_NO_MEMORY));
	line = get_next_line(so_long->map->fd);
	while (line != NULL)
	{
		if (map_parse_line(so_long, line, x) == 0)
			return (0);
		free(line);
		line = get_next_line(so_long->map->fd);
		x++;
	}
	so_long->height = x;
	so_long->map->structure = ft_realloc_dp(so_long->map->structure, x);
	close(so_long->map->fd);
	return (1);
}

/**
 * The map_open() function ..
 */
int	map_check_walls(t_server *so_long)
{
	int	i;

	i = 0;
	if (ft_strcmpchr(so_long->map->structure[0], '1') != 0
		|| ft_strcmpchr(so_long->map->structure[so_long->height - 1], '1') != 0)
		return (game_error(so_long, ERROR_WALLS));
	while (so_long->map->structure[i])
	{
		if (ft_strlen(so_long->map->structure[i]) != (size_t)so_long->width)
			return (game_error(so_long, ERROR_SIZE));
		if (so_long->map->structure[i][0] != '1' ||
			so_long->map->structure[i][so_long->width - 1] != '1')
			return (game_error(so_long, ERROR_WALLS));
		i++;
	}
	return (1);
}

/**
 * The map_check() function ..
 */
int	map_check(t_server *so_long)
{
	if (!so_long->map->spawn.x || !so_long->map->spawn.y)
		return (game_error(so_long, ERROR_NO_STARTING_POS));
	if (!so_long->map->exit.x || !so_long->map->exit.y)
		return (game_error(so_long, ERROR_NO_EXIT_POS));
	if (so_long->map->collectibles <= 0)
		return (game_error(so_long, ERROR_NO_COLLECTIBLES));
	if (map_check_walls(so_long) != 1)
		return (0);
	return (1);
}