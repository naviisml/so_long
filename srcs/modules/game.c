/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/28 13:19:09 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The game_start() function ..
 */
void	game_start(t_server *so_long)
{
	int	w;
	int	h;

	w = (so_long->width * 50);
	h = (so_long->height * 50);
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx, w, h, "so_long");
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
	(void)keycode;
	if (so_long->mlx != NULL && so_long->window != NULL)
	{
		mlx_clear_window(so_long->mlx, so_long->window);
		mlx_destroy_window(so_long->mlx, so_long->window);
	}
	if (so_long->map != NULL)
		map_deinitialize(so_long);
	if (so_long->client != NULL)
		client_deinitialize(so_long);
	exit(0);
	return (0);
}
