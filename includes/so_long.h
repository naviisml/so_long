/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/25 22:34:34 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map {
	int		fd;
	char	*fname;
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
void	map_initialize(t_server *so_long);
void	map_deinitialize(t_server *so_long);
int		map_check(t_server *so_long, char *filename);
int		map_parse(t_server *so_long);
int		events_loop(int keycode, t_server *so_long);
int		rgba(int r, int g, int b, int a);
int		get_alpha(int rgba);
int		get_red(int rgba);
int		get_green(int rgba);
int		get_blue(int rgba);

#endif