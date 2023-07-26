/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czheng-c <czheng-c@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:31:16 by czheng-c          #+#    #+#             */
/*   Updated: 2023/07/06 10:18:05 by czheng-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *dest, char *src)
{
	int		i;
	int		j;
	char	*format;

	i = 0;
	j = 0;
	format = malloc(ft_strlen(dest) + 2);
	while (dest[i] != '\0')
	{
		format[i] = dest[i];
		i++;
	}
	while (src[j] != '\0')
		format[i++] = src[j++];
	format[i] = '\0';
	return (format);
}
