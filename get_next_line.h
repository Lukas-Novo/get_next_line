/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnovotny <lnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:18:12 by lnovotny          #+#    #+#             */
/*   Updated: 2026/02/08 17:36:53 by lnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	str_len(char *str);
size_t	find_new_line(char *str, int find_null);
void	copy(char *dest, char *src, size_t start, size_t len);
void	set_buff_to_zero(char *buff);
void	replace_str(char **old, char *new);
int		alloc_line(char **line);
int		buff_to_line(char **line, char **buff);
int		alloc_buff(char **buff);
char	*non_positive_read(char **buff, char **line, int ret_null);

#endif
