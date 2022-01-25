/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parser.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/25 21:03:31 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <get_next_line.h>

/**
 * The map_parse() function ..
 * 
 * 1. Open so_long->map->fd (using get_next_line)
 * 2. Save each character in 2D-map (except newline '\n')
 * 3. Check if character is in g_map_tiles list
 * 		- True: Execute the function accosiated with the character
 * 		- False: Move on
 */
int	map_parse(t_server *so_long)
{
	char	*line;

	line = get_next_line(so_long->map->fd);
	while (line != NULL)
	{
		ft_putstr_fd(line, 0);
		free(line);
		line = get_next_line(so_long->map->fd);
	}
	close(so_long->map->fd);
	return (1);
}

/**
 * The map_open() function ..
 */
int	map_open(t_server *so_long)
{
	int		len;
	int		n;
	char	*ext;
	char	*filename;

	filename = so_long->map->file;
	len = ft_strlen(filename);
	ext = ".ber";
	n = 4;
	so_long->map->fd = open(filename, O_RDWR);
	if (so_long->map->fd < 0)
		return (game_error(so_long, "File doesnt exist"));
	while (n > 0 && filename[len - n] == *ext && filename[len - n] && *ext)
	{
		ext++;
		n--;
	}
	if (n > 0)
		return (game_error(so_long, "Invalid extension"));
	return (1);
}

/**
 * The map_check() function ..
 * 
 * 1. Check if first and last lines are walls
 * 2. Check if the first and last character of each other line is a wall
 * 3. Check if all lines are the same length
 * 4. Check if P, and E exists
 * 5. Check if there is minimum x collectibles 
 */
int	map_check(t_server *so_long)
{
	if (so_long->map->spawnpos != NULL)
		return (0);
	return (1);
}
