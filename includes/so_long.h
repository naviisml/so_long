/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/25 21:00:05 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_map {
	char	*file;
	int		fd;
	int		collectibles;
	int		**spawnpos;
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

void	server_initialize(t_server *so_long);
void	client_initialize(t_server *so_long);
void	client_deinitialize(t_server *so_long);
void	game_start(t_server *so_long);
int		game_error(t_server *so_long, char *error);
int		game_destroy(int keycode, t_server *so_long);
void	map_initialize(t_server *so_long, char *map);
int		map_open(t_server *so_long);
void	map_deinitialize(t_server *so_long);
int		events_loop(int keycode, t_server *so_long);
int		rgba(int r, int g, int b, int a);
int		get_alpha(int rgba);
int		get_red(int rgba);
int		get_green(int rgba);
int		get_blue(int rgba);

#endif