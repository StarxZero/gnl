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

int ft_strlen(char *format)
{
	int i = 0;
	if (!format)
		return (0);
	while (format[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char *one, char *two)
{
	int i = 0;
	int j = 0;
	char *temp;
	temp = malloc(ft_strlen(one) + ft_strlen(two) + 1);
	while (one[i] != '\0')
	{
		temp[i] = one[i];
		i++;
	}
	while (two[j] != '\0')
	{
		temp[i++] = two[j++];
	}
	temp[i] = '\0';
	return (temp);
}

int checking(char *value)
{
	int i = 0;
	if (!value)
	return (0);
	while (value[i] != '\0')
	{
		if (value[i++] == '\n')
			return (i);
	}
	return (0);
}

void ft_separate(char **main, char **sub)
{
    int i = 0;
	int j = 0;
	if (!**sub)
	return ;
        char *temp_main = malloc(ft_strlen(*sub) + 1);
        char *temp_sub = malloc(ft_strlen(*sub) + 1);
        while ((*sub)[i] != '\0')
        {
            temp_main[i] = (*sub)[i];
			if (temp_main[i++] == '\n')
				break ;
        }
        temp_main[i] = '\0';


        while ((*sub)[i] != '\0')
        {
            temp_sub[j++] = (*sub)[i++];
        }
        temp_sub[j] = '\0';
		
        // Update the pointers in the calling function
        free(*main);
        *main = temp_main;
        free(*sub);
        *sub = temp_sub;
	
	
}

char *get_next_line(int fd)
{
	static char *res;
	char *store;
	char *temp;
	ssize_t len = 1;
	//int i = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!res)
	{
		res = malloc(1);
		res[0] = '\0';
	}
	store = calloc(BUFFER_SIZE + 1, 1);
	while (len > 0 && checking(res) == 0)
	{
		len = read(fd, store, BUFFER_SIZE);
		if (len <= 0 || !*store)
		{
			free(store);
			store = NULL;
			break;
			//return (NULL);
		}
		store[len] = '\0';
		//printf("%lu:%s\n",len,store);
		//s
		temp = ft_strjoin(res, store);
		free(res);
		res = temp;
		//if (checking(res) != 0)
		//	break ;
				
	}
	// if (checking(res))
	ft_separate(&store, &res);
	// else
	// {
	// 	free(store);
	// 	store = res;
	// 	res = NULL;
	// }
	return (store);
}

