/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/23 22:35:36 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/**
 * so_long ...
 */
int	main(int argc, char **argv)
{
	t_server	so_long;

	if (argc != 2)
		return (ft_puterror(&so_long, "No map specified."));
	bootstrapper(&so_long, argv[1]);
	mlx_loop(so_long.mlx);
	return (0);
}
