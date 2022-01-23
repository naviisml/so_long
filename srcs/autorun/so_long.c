/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/23 21:07:49 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * so_long ...
 */
int	main(int argc, char **argv)
{
	s_server	so_long;

	if (argc != 2)
		return (window_err(&so_long, "No map"));
	initialize_server(&so_long);
	initialize_client(&so_long);
	initialize_map(&so_long, argv[1]);
	if (map_open(&so_long) == 0)
		return (0);
	if (map_parse(&so_long) == 0)
		return (0);
	window_create(&so_long);
	mlx_hook(so_long.window, 2, (1L << 0), window_destroy, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}
