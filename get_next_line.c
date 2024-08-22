/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:20:19 by czheng-c          #+#    #+#             */
/*   Updated: 2023/07/27 15:00:38 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fni(char **one, char *get)
{
	free(*one);
	*one = get;
}

void	ft_separate(char **main, char **sub)
{
	int		i;
	int		j;
	char	*temp_main;
	char	*temp_sub;

	i = 0;
	j = 0;
	if (!**sub)
	{
		fni(*(&sub), NULL);
		return ;
	}
	temp_main = ft_calloc(ft_strlen(*sub) + 1, 1);
	temp_sub = ft_calloc(ft_strlen(*sub) + 1, 1);
	while ((*sub)[i] != '\0')
	{
		temp_main[i] = (*sub)[i];
		if (temp_main[i++] == '\n')
			break ;
	}
	while ((*sub)[i] != '\0')
		temp_sub[j++] = (*sub)[i++];
	fni(*(&main), temp_main);
	fni(*(&sub), temp_sub);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*store;
	char		*temp;
	ssize_t		len;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!res)
		res = ft_calloc(1, 1);
	store = ft_calloc(BUFFER_SIZE + 1, 1);
	while (!ft_strchr(res, '\n'))
	{
		len = read(fd, store, BUFFER_SIZE);
		if (len <= 0 || !*store)
		{
			fni(&store, NULL);
			break ;
		}
		store[len] = '\0';
		temp = ft_strjoin(res, store);
		fni(&res, temp);
	}
	ft_separate(&store, &res);
	return (store);
}
