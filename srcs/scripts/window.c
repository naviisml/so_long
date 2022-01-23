/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/23 22:20:16 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The window_create() function ..
 */
int	window_create(s_server *so_long)
{
	so_long->mlx = mlx_init();
	so_long->window = mlx_new_window(so_long->mlx, 700, 300, "so_long");
	if (!so_long->window)
		return ft_puterror(so_long, "Something went wrong");
	return (1);
}

/**
 * The window_destroy() function ..
 */
int	window_destroy(s_server *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->window);
	return (0);
}
