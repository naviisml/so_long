/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 11:50:00 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <errors.h>

typedef struct s_server t_server;
typedef struct s_map t_map;
typedef struct s_sprite t_sprite;
typedef struct s_events t_events;

void	server_initialize(t_server *server);
void	game_start(t_server *so_long);
int		game_error(t_server *so_long, char *error);
int		game_destroy(int keycode, t_server *so_long);
void	map_initialize(t_server *so_long);
void	map_deinitialize(t_server *so_long);
int		map_open(t_server *so_long, char *filename);
int		map_parse(t_server *so_long);
int		map_check(t_server *so_long);
void	map_draw(t_server *so_long);
int		events_loop(int keycode, t_server *so_long);

int		rgba(int r, int g, int b, int a);
int		get_alpha(int rgba);
int		get_red(int rgba);
int		get_green(int rgba);
int		get_blue(int rgba);

t_sprite	sprite_create(t_server *server, char *path);
void		sprite_draw(t_server *server, t_sprite *image, int x, int y);
void		sprite_destroy(t_server *server, t_sprite *image);
void		sprite_pixel_put(t_sprite *image, int color, int x, int y);

int		example_walk(int keycode, t_server *so_long);

int		example_function(t_server *so_long, char c, int x, int y);
int		set_map_spawn(t_server *so_long, char c, int x, int y);
int		set_map_exit(t_server *so_long, char c, int x, int y);
int		add_map_collectible(t_server *so_long, char c, int x, int y);

typedef struct s_vector {
	int			x;
	int			y;
	int			width;
	int			height;
}			t_vector;

typedef struct s_sprite {
	void		*pointer;
	char		*pixels;
	int			bits_per_pixel;
	int			bits_per_row;
	int			endian;
	t_vector	size;
}				t_sprite;

typedef struct s_events {
	char		keycode;
	int			(*callback)();
}				t_events;

typedef struct s_server {
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	t_map		*map;
}				t_server;

typedef struct s_map {
	int			fd;
	char		*fname;
	int			collectibles;
	char		**structure;
	t_vector	spawn;
	t_vector	exit;
	t_sprite	player;
}				t_map;

typedef struct s_map_tiles {
	char	c;
	int		(*callback)(t_server *, char, int, int);
}			t_map_tiles;

#endif