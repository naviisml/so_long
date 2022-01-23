/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/23 22:33:02 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXAMPLE_H
# define FT_EXAMPLE_H

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

typedef struct t_map {
	char	*file;
	int		fd;
	int		collectibles;
	int		**spawnpos;
	char	**structure;
}			s_map;

typedef struct t_client {
	int		x;
	int		y;
	int		collected;
}			s_client;

typedef struct t_server {
	void		*mlx;
	void		*window;
	s_map		*map;
	s_client	*client;
}				s_server;

void	bootstrapper(s_server *so_long, char *map);
void	initialize_client(s_server *so_long);
void	initialize_server(s_server *so_long);
void	initialize_map(s_server *so_long, char *map);
int		map_open(s_server *so_long);
int		map_parse(s_server *so_long);
int		window_create(s_server *so_long);
int		window_destroy(s_server *so_long);
int		ft_puterror(s_server *so_long, char *error);
int		events_initialize(s_server *so_long);
int		rgba(int r, int g, int b, int a);
int		get_alpha(int rgba);
int		get_red(int rgba);
int		get_green(int rgba);
int		get_blue(int rgba);

#endif