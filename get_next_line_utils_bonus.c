/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarob <ncarob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 19:01:26 by ncarob            #+#    #+#             */
/*   Updated: 2021/10/18 22:57:33 by ncarob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
	return (NULL);
}

char	*add_buffer(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	if (!s1 && !s2)
		return (NULL);
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (str)
		str[i + j] = 0;
	while (str && s2 && j-- > 0)
		str[i + j] = s2[j];
	while (str && s1 && i-- > 0)
		str[i] = s1[i];
	if (s1)
		free((void *)s1);
	return (str);
}
