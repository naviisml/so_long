/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 11:47:15 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/*
 * The sprite_create() function ...
 */
t_sprite	sprite_create(t_server *server, char *path)
{
	t_sprite	texture;

	texture.pointer = mlx_xpm_file_to_image(server->mlx, path, &texture.size.width, &texture.size.height);
	texture.pixels = mlx_get_data_addr(texture.pointer, &texture.bits_per_pixel, &texture.bits_per_row, &texture.endian);
	return (texture);
}

/*
 * The sprite_draw() function ...
 */
void	sprite_draw(t_server *server, t_sprite *image, int x, int y)
{
	mlx_put_image_to_window(server->mlx, server->window, image->pointer, x, y);
}

/*
 * The sprite_destroy() function ...
 */
void	sprite_destroy(t_server *server, t_sprite *image)
{
	mlx_destroy_image(server->mlx, image->pointer);
}

/*
 * The sprite_pixel_put() function ...
 */
void	sprite_pixel_put(t_sprite *image, int color, int x, int y)
{
	char	*dst;

	dst = image->pointer + (y * image->bits_per_row + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
