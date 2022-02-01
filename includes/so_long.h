/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/01 11:29:53 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <errors.h>

typedef struct s_map {
	int		fd;
	char	*fname;
	int		collectibles;
	int		*spawn;
	int		*exit;
	char	**structure;
}			t_map;

typedef struct s_client {
	int		x;
	int		y;
	int		collected;
}			t_client;

typedef struct s_server {
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	t_map		*map;
	t_client	*client;
}				t_server;

typedef struct s_events {
	char		keycode;
	int			(*callback)();
}				t_events;

typedef struct s_map_tiles {
	char	c;
	int		(*callback)(t_server *, char, int, int);
}			t_map_tiles;

typedef struct s_sprite {
	char	*path;
	void	*image;
	int		width;
	int		height;
	int		x;
	int		y;
}			t_sprite;

void	server_initialize(t_server *so_long);
void	client_initialize(t_server *so_long);
void	client_deinitialize(t_server *so_long);
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
void	*draw_sprite(t_server *so_long, t_sprite *image);

int		example_function(t_server *so_long, char c, int x, int y);
int		set_map_spawn(t_server *so_long, char c, int x, int y);
int		set_map_exit(t_server *so_long, char c, int x, int y);
int		add_map_collectible(t_server *so_long, char c, int x, int y);

#endif