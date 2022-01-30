/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 00:27:03 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/30 01:38:31 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR_STARTING_POS	"The map has more then 1 starting positions."
# define ERROR_EXIT_POS	"The map has more then 1 exit positions."
# define ERROR_WALLS	"The map must be surrounded by walls."
# define ERROR_SIZE	"The map must be rectangular."
# define ERROR_TILES	"The map contains a illegal character."
# define ERROR_NO_STARTING_POS	"The map must contain 1 starting position."
# define ERROR_NO_EXIT_POS	"The map must contain 1 exit position."
# define ERROR_NO_COLLECTIBLES	"The map must contain atleast 1 collectible."
# define ERROR_NO_ARGS	"Invalid arguments; try './so_long <path/to/map>'"

# define ERROR_NO_MEMORY	"No available memory."

# define ERROR_FILE_NOT_FOUND	"The map file could not be read."
# define ERROR_FILE_EXTENSION	"The map file must be a '.ber' map"

#endif