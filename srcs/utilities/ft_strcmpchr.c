/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmpchr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nismail <nismail@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 04:14:45 by nismail       #+#    #+#                 */
/*   Updated: 2022/01/30 01:28:03 by nismail       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

/*
 * The ft_strcmpchr() functions lexicographically compare 
 * the null-terminated string str with char c.
 * 
 * This is subject to change, and therefor not included in libft (yet)
 */
int	ft_strcmpchr(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return ((int)str[i] - c);
}
