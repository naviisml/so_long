/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/28 12:04:49 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <get_next_line.h>

/**
 * The map_parse_line() function ..
 */
static int	map_parse_line(t_server *so_long, char *line, int x)
{
	int	y;

	y = 0;
	so_long->map->structure[x] = (char *)malloc(ft_strlen(line));
	if (!so_long->map->structure[x])
		return (0);
	while (line[y] != '\0' && line[y] != '\n')
	{
		so_long->map->structure[x][y] = line[y];
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
	int		i;

	i = 0;
	so_long->map->structure = (char **)malloc(sizeof(char **) * 100);
	if (!so_long->map->structure)
		return (0);
	line = get_next_line(so_long->map->fd);
	while (line != NULL)
	{
		i++;
		map_parse_line(so_long, line, i);
		free(line);
		line = get_next_line(so_long->map->fd);
	}
	ft_realloc_dp(so_long->map->structure, i);
	close(so_long->map->fd);
	return (1);
}
