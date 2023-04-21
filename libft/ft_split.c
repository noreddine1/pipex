/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:07:15 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/08 16:04:29 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static	int	ft_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **strs, int i)
{
	while (i >= 0)
	{
		free(strs[i--]);
	}
	free(strs);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!strs)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len != 0)
			strs[i++] = ft_substr(s, 0, len);
		if (len != 0 && !strs[i - 1])
			return (ft_free(strs, i - 1));
		s += len;
	}
	strs[i] = NULL;
	return (strs);
}
