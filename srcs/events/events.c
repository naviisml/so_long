/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/23 22:12:14 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/06 13:22:01 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The g_key_events struct ...
 */
t_events	g_key_events[] = {
{53, game_destroy},
{0, client_move_left},
{13, client_move_up},
{1, client_move_down},
{2, client_move_right},
};

/**
 * The event_check() function ...
 */
int	events_loop(int keycode, t_server *so_long)
{
	int	i;
	int	res;

	i = 0;
	while (g_key_events[i].callback != NULL)
	{
		if (g_key_events[i].keycode == keycode)
		{
			res = g_key_events[i].callback(keycode, so_long);
			return (res);
		}
		i++;
	}
	return (1);
}
