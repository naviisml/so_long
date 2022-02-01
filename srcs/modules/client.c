/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:26:25 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/01 13:39:20 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	client_draw(t_server *so_long)
{
	t_sprite	*character;
	void		*image;

	character = malloc(sizeof(t_sprite));
	character->path = "./resources/assets/character.png";
	character->width = 32;
	character->height = 32;
	character->x = (so_long->client->x * 32);
	character->y = (so_long->client->y * 32);
	image = draw_sprite(so_long, character);
	so_long->client->sprite = &image;
}
