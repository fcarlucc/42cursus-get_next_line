/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:58:20 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/02/21 11:58:27 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[4096][BUFFER_SIZE + 1];
	char		*readline;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, buff[fd], 0) < 0 || fd >= 4096)
	{
		while (fd >= 0 && fd <= 4096 && buff[fd][i])
			buff[fd][i++] = 0;
		return (NULL);
	}
	readline = NULL;
	while (*buff[fd] || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		readline = ft_strjoin(readline, buff[fd]);
		if (ft_cleanbuff(buff[fd]))
			break ;
	}
	return (readline);
}
