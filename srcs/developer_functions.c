/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   developer_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/02 10:16:46 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <stdio.h>

/**
 * The debug_print_map() function ...
 */
int	debug_print_map(t_server *so_long)
{
	ft_putstr_fd("-------\n", 0);
	printf("Collectibles: %d\n", so_long->map->collectibles);
	ft_putstr_fd("-------\n", 0);
	/*while (so_long->map->structure[x] != NULL)
	{
		y = 0;
		while (so_long->map->structure[x][y] != '\0')
		{
			ft_putchar_fd(so_long->map->structure[x][y], 0);
			y++;
		}
		ft_putchar_fd('\n', 0);
		x++;
	}*/
	return (1);
}
