/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 15:59:49 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/*
 * The ft_mlx_pixel_get() function ...
 */
unsigned int	ft_mlx_pixel_get(t_sprite *texture, int x, int y)
{
	return (*(unsigned int *)
		(texture->data + (x * texture->bpp / 8 + y * texture->size_l)));
}

/*
 * The ft_mlx_pixel_draw() function ...
 */
void	ft_mlx_pixel_draw(t_sprite *texture, int color, int x, int y)
{
	char	*dst;

	dst = texture->data + (x * texture->bpp / 8 + y * texture->size_l);
	*(unsigned int *)dst = color;
}
