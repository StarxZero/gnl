/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:35:24 by czheng-c          #+#    #+#             */
/*   Updated: 2023/07/06 16:40:58 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*reading(int fd, char *res, char *store, ssize_t len)
{
	char	*temp;
	int		i;

	i = 0;
	while (len > 0)
	{
		len = read(fd, store, BUFFER_SIZE - BUFFER_SIZE + 1);
		if (len == -1 || !*store)
		{
			free(res);
			free(store);
			return (NULL);
		}
		store[len] = '\0';
		temp = ft_strjoin(res, store);
		free(res);
		res = temp;
		if (res[i++] == '\n')
			break ;
	}
	free(store);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*store;
	static char	**res;
	ssize_t		len;
	long		max_fd;

	len = 1;
	max_fd = sysconf(_SC_OPEN_MAX);
	if (fd < 0 || BUFFER_SIZE < 0 || fd > max_fd)
		return (NULL);
	res = malloc(max_fd);
	res[fd] = malloc(1);
	res[fd][0] = '\0';
	store = malloc(2);
	res[fd] = reading(fd, res[fd], store, len);
	free(res);
	return (res[fd]);
}
