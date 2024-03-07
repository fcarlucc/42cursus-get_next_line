/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:32:40 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/08/25 17:01:57 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*readline;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	readline = NULL;
	while (*buff || read(fd, buff, BUFFER_SIZE) > 0)
	{
		readline = ft_strjoin(readline, buff);
		if (ft_cleanbuff(buff))
			break ;
	}
	return (readline);
}
