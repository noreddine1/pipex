/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:44:18 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/08 16:04:49 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_contains(unsigned char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	if (j)
		j--;
	while ((ft_contains((unsigned char *)set, (unsigned char) s1[i])))
		i++;
	while (ft_contains((unsigned char *)set, (unsigned char)s1[j]) && i < j)
		j--;
	len = j - i + 1;
	if (j > i)
		str = ft_substr(s1, i, len);
	else if (j < i)
		str = ft_strdup("\0");
	else
		str = ft_substr(s1, i, 1);
	return (str);
}
