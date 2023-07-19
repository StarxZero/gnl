/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:20:19 by czheng-c          #+#    #+#             */
/*   Updated: 2023/07/19 17:28:39 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *trim(char **format)
{
	int i = 0;
	char *temp;
	if (!**format)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	while (**format != '\0')
	{
		temp[i++] = **format;
		if (*(*format)++ == '\n')
			break ;
	}
   	temp[i] = '\0';
	return (temp);
}

char *get_next_line(int fd)
{
	static char *res;
	char *store;
	char *temp;
	ssize_t len = 1;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!res)
	{
		store = malloc(BUFFER_SIZE + 1);
		res = malloc(BUFFER_SIZE + 1);
		res[BUFFER_SIZE + 1] = '\0';
		while (len > 0)
		{
			len = read(fd, store, BUFFER_SIZE);
			if (len == -1 || !*store)
			{
				break ;
			}
			store[len] = '\0';
			temp = ft_strjoin(res, store);
			free(res);
			res = temp;
		}
		free(store);
	}
	store = trim(&res);
	return (store);
}
