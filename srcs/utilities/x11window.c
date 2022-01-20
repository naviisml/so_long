/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   x11window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/20 14:12:29 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The window_create() function ..
 */
int	window_create(s_server *so_long)
{
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx, 1920, 1080, "so_long");
	return (1);
}

/**
 * The window_err() function ..
 */
int	window_err(s_server *so_long, char *error)
{
	ft_putstr_fd("Error\n", 0);
	if (error != NULL)
		ft_putstr_fd(error, 0);
	window_destroy(so_long);
	return (0);
}

/**
 * The window_destroy() function ..
 */
int	window_destroy(s_server *so_long)
{
	if (so_long->mlx && so_long->window)
		mlx_destroy_window(so_long->mlx, so_long->window);
	return (0);
}
