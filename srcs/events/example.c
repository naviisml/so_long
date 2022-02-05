/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/04 18:19:37 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The example_function() function ..
 */
int	example_function(t_server *so_long, char c, int x, int y)
{
	(void)so_long;
	(void)c;
	(void)x;
	(void)y;
	return (1);
}

/**
 * The example_function() function ..
 */
int	example_walk(int keycode, t_server *so_long)
{
	(void)keycode;
	so_long->map->player.size.x += 10;
	so_long->map->player.size.y += 10;
	return (1);
}
