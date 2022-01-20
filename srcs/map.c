/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/20 14:28:41 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The map_check_file() function ..
 */
static int	map_check_file(s_server *so_long)
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
		return (window_err(so_long, "File doesnt exist"));
	while (n > 0 && filename[len - n] == *ext && filename[len - n] != '\0')
	{
		ext++;
		n--;
	}
	if (n > 0)
		return (window_err(so_long, "Invalid extension"));
	return (1);
}

/**
 * The map_parse() function ..
 */
int	map_parse(s_server *so_long)
{
	int	status;

	status = map_check_file(so_long);
	return (status);
}
