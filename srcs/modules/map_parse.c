/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/28 11:46:29 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <get_next_line.h>

/**
 * The map_parse() function ..
 */
int	map_parse(t_server *so_long)
{
	char	*line;
	int		x;
	int		y;

	so_long->map->structure = (char **)malloc(sizeof(char **) * 100);
	line = get_next_line(so_long->map->fd);
	x = 0;
	while (line != NULL)
	{
		y = 0;
		so_long->map->structure[x] = (char *)malloc(ft_strlen(line));
		while (line[y] != '\0' && line[y] != '\n')
		{
			so_long->map->structure[x][y] = line[y];
			y++;
		}
		free(line);
		line = get_next_line(so_long->map->fd);
		x++;
	}
	ft_realloc_dp(so_long->map->structure, x);
	close(so_long->map->fd);
	return (1);
}
