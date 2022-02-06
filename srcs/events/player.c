/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 12:55:08 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The client_check() function ..
 */
static int	client_check(t_server *so_long, int x, int y)
{
	if (so_long->map->structure[y][x] == '1')
	{
		return (0);
	}
	else if (so_long->map->structure[y][x] == 'C')
	{
		so_long->map->structure[y][x] = '0';
		so_long->map->collectibles -= 1;
		if (so_long->map->collectibles == 0)
			so_long->map->door = sprite_create
				(so_long, "./resources/assets/door-unlocked.xpm");
	}
	else if (so_long->map->structure[y][x] == 'E')
	{
		if (so_long->map->collectibles != 0)
			return (0);
		game_print_moves(so_long);
		game_destroy(0, so_long);
	}
	return (1);
}

/**
 * The client_move_left() function ..
 */
int	client_move_left(int keycode, t_server *so_long)
{
	int	x;
	int	y;

	(void)keycode;
	x = so_long->map->player.size.x - 1;
	y = so_long->map->player.size.y;
	if (client_check(so_long, x, y) == 0)
		return (1);
	so_long->map->player = sprite_create
		(so_long, "./resources/assets/character-4.xpm");
	so_long->map->player.size.x = x;
	so_long->map->player.size.y = y;
	game_print_move(so_long, "left");
	return (1);
}

/**
 * The client_move_right() function ..
 */
int	client_move_right(int keycode, t_server *so_long)
{
	int	x;
	int	y;

	(void)keycode;
	x = so_long->map->player.size.x + 1;
	y = so_long->map->player.size.y;
	if (client_check(so_long, x, y) == 0)
		return (1);
	so_long->map->player = sprite_create
		(so_long, "./resources/assets/character-2.xpm");
	so_long->map->player.size.x = x;
	so_long->map->player.size.y = y;
	game_print_move(so_long, "right");
	return (1);
}

/**
 * The client_move_up() function ..
 */
int	client_move_up(int keycode, t_server *so_long)
{
	int	x;
	int	y;

	(void)keycode;
	x = so_long->map->player.size.x;
	y = so_long->map->player.size.y - 1;
	if (client_check(so_long, x, y) == 0)
		return (1);
	so_long->map->player = sprite_create
		(so_long, "./resources/assets/character-1.xpm");
	so_long->map->player.size.x = x;
	so_long->map->player.size.y = y;
	game_print_move(so_long, "up");
	return (1);
}

/**
 * The client_move_down() function ..
 */
int	client_move_down(int keycode, t_server *so_long)
{
	int	x;
	int	y;

	(void)keycode;
	x = so_long->map->player.size.x;
	y = so_long->map->player.size.y + 1;
	if (client_check(so_long, x, y) == 0)
		return (1);
	so_long->map->player = sprite_create
		(so_long, "./resources/assets/character-3.xpm");
	so_long->map->player.size.x = x;
	so_long->map->player.size.y = y;
	game_print_move(so_long, "down");
	return (1);
}
