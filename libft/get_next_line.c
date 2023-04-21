/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:18:44 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/05 11:39:09 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char const *s1, char *s2)
{
	int		size1;
	int		size2;
	char	*str;
	int		total;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	total = size1 + size2;
	str = (char *) malloc(total * sizeof(char) + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, size1 + 1);
	ft_strlcpy(str + size1, s2, size2 + 1);
	return (str);
}

static char	*ft_get_line(char **stock, int len)
{
	char	*line;
	char	*tmp;
	int		size;

	size = ft_strlen(*stock);
	line = ft_substr(*stock, 0, len + 1);
	tmp = *stock;
	*stock = ft_substr(*stock, len + 1, size - len);
	free(tmp);
	return (line);
}

static int	is_nl(char *str, int *i)
{
	if (str)
	{
		while (str[*i])
		{
			if (str[*i] == '\n')
				return (1);
			(*i)++;
		}
	}
	return (0);
}

static char	*ft_read(int fd, char *stock, int *len)
{
	char	*buffer;
	char	*tmp;
	int		read_len;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (free(stock), NULL);
	while (!is_nl(stock, len))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == 0 && !stock)
			return (free(buffer), NULL);
		if (read_len == -1)
			return (free(buffer), free(stock), NULL);
		if (read_len == 0 && stock)
			break ;
		buffer[read_len] = '\0';
		tmp = stock;
		stock = ft_join(stock, buffer);
		if (tmp)
			free(tmp);
	}
	return (free(buffer), stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[100];
	char		*line;
	int			len;

	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = ft_read(fd, stock[fd], &len);
	if (stock[fd] && *stock[fd])
		line = ft_get_line(&stock[fd], len);
	else
		line = NULL;
	return (line);
}
