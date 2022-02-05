/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 12:25:04 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The client_move_left() function ..
 */
int	client_move_left(int keycode, t_server *so_long)
{
	int	x;
	(void)keycode;
	x = so_long->map->player.size.x - 1;
	so_long->map->player.size.x = x;
	return (1);
}

/**
 * The client_move_right() function ..
 */
int	client_move_right(int keycode, t_server *so_long)
{
	int	x;
	(void)keycode;
	x = so_long->map->player.size.x + 1;
	so_long->map->player.size.x = x;
	return (1);
}

/**
 * The client_move_up() function ..
 */
int	client_move_up(int keycode, t_server *so_long)
{
	int	y;
	(void)keycode;
	y = so_long->map->player.size.y - 1;
	so_long->map->player.size.y = y;
	return (1);
}

/**
 * The client_move_down() function ..
 */
int	client_move_down(int keycode, t_server *so_long)
{
	int	y;
	(void)keycode;
	y = so_long->map->player.size.y + 1;
	so_long->map->player.size.y = y;
	return (1);
}
