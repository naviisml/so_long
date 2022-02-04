/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/23 22:12:14 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/04 17:55:00 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The g_key_events struct ...
 */
t_events	g_key_events[] = {
{53, game_destroy},
{2, example_walk},
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
	ft_putstr_fd("[DEBUG] No bind on ", 0);
	ft_putnbr_fd(keycode, 0);
	ft_putchar_fd('\n', 0);
	return (1);
}
