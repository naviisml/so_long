/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 13:17:59 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/*
 * The ft_mlx_pixel_get() function ...
 */
unsigned int	ft_mlx_pixel_get(t_sprite *texture, int x, int y)
{
	return (*(unsigned int *)(texture->pixels + (x * texture->bits_per_pixel / 8 + y * texture->bits_per_row)));
}

/*
 * The ft_mlx_pixel_draw() function ...
 */
void	ft_mlx_pixel_draw(t_sprite *image, int color, int x, int y)
{
	char	*dst;

	dst = image->pixels + (x * image->bits_per_pixel / 8 + y * image->bits_per_row);
	*(unsigned int *)dst = color;
}