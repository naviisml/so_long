/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/23 21:08:41 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The initialize_server() function ..
 */
void	initialize_server(s_server *so_long)
{
	so_long->mlx = NULL;
	so_long->window = NULL;
}