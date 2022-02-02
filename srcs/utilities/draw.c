/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/02 10:13:30 by navi          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	*draw_sprite(t_server *c, t_sprite *img)
{
	void	*image;

	image = mlx_xpm_file_to_image(c->mlx, img->path, &img->width, &img->height);
	img->image = image;
	mlx_put_image_to_window(c->mlx, c->window, img->image, img->y, img->x);
	return (image);
}
