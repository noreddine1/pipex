/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 02:45:26 by nmaazouz          #+#    #+#             */
/*   Updated: 2022/10/31 22:03:48 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	unsigned int	size_s;

	if (!s || !f)
		return (NULL);
	i = 0;
	size_s = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * size_s + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s, size_s + 1);
	while (str[i])
	{
		str[i] = (f)(i, str[i]);
		i++;
	}
	return (str);
}
