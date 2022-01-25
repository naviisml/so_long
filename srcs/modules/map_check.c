/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/25 22:02:00 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
	while (i > 0 && ext[i] && filename[pos])
	{
		if (ext[i] != filename[pos])
			return (0);
		pos--;
		i--;
	}
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
 * The map_check() function ..
 */
int	map_check(t_server *so_long, char *filename)
{
	if (map_ext(filename) == 0)
		return (game_error(so_long, "Invalid extension"));
	else if (map_exists(so_long, filename) == 0)
		return (game_error(so_long, "File doesnt exist"));
	return (1);
}
