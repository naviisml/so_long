/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/25 20:29:04 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The client_initialize() function ..
 */
void	client_initialize(t_server *so_long)
{
	so_long->client = malloc(sizeof(struct s_client));
	so_long->client->x = 0;
	so_long->client->y = 0;
	so_long->client->collected = 0;
}
