/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:17:49 by lnovotny          #+#    #+#             */
/*   Updated: 2026/02/08 17:51:57 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	alloc_line(char **line)
{
	if (*line == NULL)
	{
		*line = malloc(sizeof(char));
		if (*line == NULL)
			return (0);
		(*line)[0] = '\0';
	}
	return (1);
}

int	buff_to_line(char **line, char **buff)
{
	char	*new_line;
	char	*new_buff;
	size_t	len_line;
	size_t	len_buff_to_n;
	size_t	len_buff_aft_n;

	if (!alloc_line(line))
		return (0);
	len_line = str_len(*line);
	len_buff_to_n = find_new_line(*buff, 1);
	len_buff_aft_n = str_len(*buff) - len_buff_to_n;
	new_line = malloc((len_line + len_buff_to_n + 1) * sizeof(char));
	if (new_line == NULL)
		return (0);
	new_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (new_buff == NULL)
		return (0);
	set_buff_to_zero(new_buff);
	copy(new_line, *line, 0, len_line);
	copy(new_line, *buff, len_line, len_buff_to_n);
	copy(new_buff, *buff + len_buff_to_n, 0, len_buff_aft_n);
	replace_str(line, new_line);
	replace_str(buff, new_buff);
	return (1);
}

int	alloc_buff(char **buff)
{
	*buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (*buff == NULL)
		return (0);
	set_buff_to_zero(*buff);
	return (1);
}

char	*non_positive_read(char **buff, char **line, int ret_null)
{
	if (*line && str_len(*line) == 0)
	{
		free(*line);
		*line = NULL;
	}
	free(*buff);
	*buff = NULL;
	if (ret_null)
		return (NULL);
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;
	ssize_t		bytes_read;

	line = NULL;
	if (buff == NULL && !alloc_buff(&buff))
		return (NULL);
	else if (buff_to_line(&line, &buff) == 0)
		return (NULL);
	else if (find_new_line(line, 0))
		return (line);
	while (find_new_line(buff, 0) == 0)
	{
		if (buff_to_line(&line, &buff) == 0)
			return (NULL);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == 0)
			return (non_positive_read(&buff, &line, 0));
		else if (bytes_read < 0)
			return (non_positive_read(&buff, &line, 1));
	}
	if (buff_to_line(&line, &buff) == 0)
		return (NULL);
	return (line);
}
