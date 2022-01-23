/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   developer_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/23 22:21:03 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * The ft_puterror() function ..
 */
int	ft_puterror(s_server *so_long, char *error)
{
	ft_putstr_fd("Error\n", 0);
	if (error != NULL)
		ft_putstr_fd(error, 0);
	window_destroy(so_long);
	return (0);
}
