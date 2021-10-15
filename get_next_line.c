#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(char *)(s + i) = (char)c;
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
	if (s[i] == (unsigned char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (s1)
		free((void *)s1);
	j = 0;
	while (s2 && s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	i = -1;
	if (!s)
		size = 0;
	else
		size = ft_strlen(s);
	if (size < start)
		len = 0;
	else if (size - start < len)
		len = size;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = 0;
	return (str);
}


char	*get_next_line(int fd)
{
	char		*buffers;
	char		*end;
	static char	buf[BUFFER_SIZE + 1];
	int			ret;

	buffers = NULL;
	//if (buf[0])
	//{
	//	if (ft_strchr(buf, '\n'))
	//		buffers = ft_strjoin(buffers, buf);
	//}
	end = NULL;
	ret = 1;
	while (!end && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (!ret)
			return (buffers);
		buf[ret] = 0;
		buffers = ft_strjoin(buffers, buf);
		end = ft_strchr(buf, '\n');
	}
	if (!end)
		return (NULL);
	*(end + 1) = '\0';
	return (buffers);
}