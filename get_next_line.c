/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:45:22 by ncarob            #+#    #+#             */
/*   Updated: 2021/10/16 21:58:26 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	ssize_t		ret;
	char		*end;
	char		*result;

	ret = 1;
	end = NULL;
	result = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (buf[0])
	{
		result = ft_strdup(ft_strchr(buf, '\n') + 1);
		*(ft_strchr(buf, '\n')) = 'z';
		end = ft_strchr(result, '\n');
	}
	while (ret && !end)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (!ret || ret == -1)
			break ;
		else
		{
			buf[ret] = 0;
			if (!result)
				result = ft_strdup(buf);
			else
				result = ft_strjoin(result, buf);
			end = ft_strchr(result, '\n');
		}
	}
	if (end)
		*(end + 1) = 0;
	return (result);
}
