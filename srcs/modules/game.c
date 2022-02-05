/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 15:57:49 by nismail       ########   odam.nl         */
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

	w = (so_long->width * 32);
	h = (so_long->height * 32);
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx, w, h, "so_long");
	so_long->data.pointer = mlx_new_image(so_long->mlx, w, h);
	so_long->data.data = mlx_get_data_addr(so_long->data.pointer,
			&so_long->data.bpp, &so_long->data.size_l, &so_long->data.endian);
	so_long->data.width = w;
	so_long->data.height = h;
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
	(void)so_long;
	exit(0);
	return (0);
}
