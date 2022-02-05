/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textures.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 16:00:11 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/*
 * The sprite_create() function ...
 */
t_sprite	sprite_create(t_server *server, char *path)
{
	t_sprite	texture;
	int			width;
	int			height;

	texture.pointer = mlx_xpm_file_to_image(server->mlx, path, &width, &height);
	texture.data = mlx_get_data_addr
		(texture.pointer, &texture.bpp, &texture.size_l, &texture.endian);
	texture.width = width;
	texture.height = height;
	return (texture);
}

/*
 * The sprite_paint() function ...
 */
void	sprite_paint(t_server *server, t_sprite *image, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			color = ft_mlx_pixel_get(image, i, j);
			if (color != rgba(0, 0, 0, 255))
				ft_mlx_pixel_draw(&server->data, color, x + i, y + j);
			i++;
		}
		j++;
	}
}

/*
 * The sprite_put() function ...
 */
void	sprite_put(t_server *server, t_sprite *image, int x, int y)
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
