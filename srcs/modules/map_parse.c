/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_parse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/25 21:55:21 by nismail       ########   odam.nl         */
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
