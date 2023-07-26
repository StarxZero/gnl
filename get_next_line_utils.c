/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:42:57 by czheng-c          #+#    #+#             */
/*   Updated: 2023/07/18 10:31:13 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "get_next_line.h"

int	ft_strlen(char *format)
{
	int	i;

	i = 0;
	if (!format)
		return (0);
	while (format[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*format;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	format = calloc(ft_strlen(str1) + ft_strlen(str2) + 2, 1);
	if (!format)
		return (NULL);
	while (str1[i] != '\0')
	{
		format[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		format[i++] = str2[j++];
	}
	//format[i] = '\0';
	return (format);
}
*/