/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bootstrapper.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/23 22:28:09 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The bootstrapper() function ...
 */
void	bootstrapper(s_server *so_long, char *map)
{
	initialize_server(so_long);
	initialize_client(so_long);
	initialize_map(so_long, map);
	events_initialize(so_long);
}
