/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:26:53 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/08 16:05:13 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*ptr;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= (int)start)
		return (ft_strdup(""));
	if (s_len < len)
		len = s_len;
	ptr = (char *) malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
