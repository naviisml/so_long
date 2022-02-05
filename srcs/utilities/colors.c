/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 04:14:45 by nismail       #+#    #+#                 */
/*   Updated: 2022/02/05 13:20:08 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/*
 * The rgba() function ...
 */
unsigned int	rgba(int r, int g, int b, int a)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

/*
 * The get_alpha() function ...
 */
int	get_alpha(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

/*
 * The get_red() function ...
 */
int	get_red(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

/*
 * The get_green() function ...
 */
int	get_green(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

/*
 * The get_blue() function ...
 */
int	get_blue(int rgba)
{
	return (rgba & 0xFF);
}
