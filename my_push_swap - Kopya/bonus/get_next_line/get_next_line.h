/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:24:14 by mdinc             #+#    #+#             */
/*   Updated: 2025/05/22 22:23:40 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

size_t	ft_strlen_gnl(char *s);
int		ft_count_newline(char *remainder);
char	*ft_where_newline(char *s);
char	*ft_strjoin_gnl(char *remainder, char *temp);
char	*ft_strchr(const char *s, int c);

#endif
