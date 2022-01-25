/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/25 20:59:52 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The game_start() function ..
 */
void	game_start(t_server *so_long)
{
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx, so_long->width, so_long->height, "so_long");
}

/**
 * The game_error() function ..
 */
int	game_error(t_server *so_long, char *message)
{
	ft_putstr_fd("Error\n", 0);
	if (message != NULL)
		ft_putstr_fd(message, 0);
	game_destroy(0, so_long);
	return (0);
}

/**
 * The game_destroy() function ..
 */
int	game_destroy(int keycode, t_server *so_long)
{
	keycode = 0;
	mlx_clear_window(so_long->mlx, so_long->window);
	mlx_destroy_window(so_long->mlx, so_long->window);
	exit(0);
	return (0);
}
