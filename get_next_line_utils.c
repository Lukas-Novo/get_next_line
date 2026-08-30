/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:18:02 by lnovotny          #+#    #+#             */
/*   Updated: 2026/02/08 18:13:54 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

size_t	find_new_line(char *str, int find_null)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] == '\n')
		return (i + 1);
	else
	{
		if (find_null)
			return (i);
		else
			return (0);
	}
}

void	copy(char *dest, char *src, size_t start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[start + i] = src[i];
		++i;
	}
	dest[start + i] = '\0';
}

void	set_buff_to_zero(char *buff)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buff[i] = '\0';
		++i;
	}
}

void	replace_str(char **old, char *new)
{
	free(*old);
	*old = new;
}
