/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:57:41 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/08 11:22:20 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char *s2)
{
	int		size1;
	int		size2;
	char	*str;
	int		total;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	total = size1 + size2;
	str = (char *) malloc(total * sizeof(char) + 2);
	if (!str)
		return (0);
	ft_memcpy(str, s1, size1);
	ft_memcpy(str + size1, s2, size2);
	ft_memcpy(str + total, " ", 1);
	ft_bzero(str + total + 1, 1);
	if (!*s1)
		free((char *)s1);
	return (str);
}
