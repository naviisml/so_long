/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/23 22:12:14 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/23 22:34:00 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The event_check() function ...
 */
int	events_loop(void)
{
	return (1);
}

/**
 * The event_execute() function ...
 */
int	events_initialize(s_server *so_long)
{
	mlx_hook(so_long->window, 2, (1L << 0), window_destroy, so_long);
	return (1);
}
