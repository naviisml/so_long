/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/30 01:26:06 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

/**
 * The map_ext() function ..
 */
static int	map_ext(char *filename)
{
	char	*ext;
	int		i;
	int		pos;

	ext = ".ber";
	i = ft_strlen(ext);
	pos = ft_strlen(filename);
	while (i >= 0)
	{
		if (ext[i] != filename[pos])
			break ;
		pos--;
		i--;
	}
	if (i >= 0)
		return (0);
	return (1);
}

/**
 * The map_exists() function ..
 */
static int	map_exists(t_server *so_long, char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (0);
	so_long->map->fname = filename;
	so_long->map->fd = fd;
	return (1);
}

/**
 * The map_open() function ..
 */
int	map_open(t_server *so_long, char *filename)
{
	if (map_exists(so_long, filename) == 0)
		return (game_error(so_long, ERROR_FILE_NOT_FOUND));
	if (map_ext(filename) == 0)
		return (game_error(so_long, ERRPR_FILE_EXTENSION));
	return (1);
}
