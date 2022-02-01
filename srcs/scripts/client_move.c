/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/01 13:45:56 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/*
 * The client_move_right() function ...
 */
int	client_move_right(t_server *so_long, int x, int y)
{
	(void)x;
	(void)y;
	mlx_clear_window(so_long->mlx, so_long->window);
	so_long->client->tile[1] = 2;
	return (1);
}
