/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/28 12:56:56 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The example_function() function ..
 */
void	example_function(t_server *so_long, char c, int x, int y)
{
	(void)so_long;
	(void)x;
	(void)y;
	
	ft_putchar_fd(c, 0);
}