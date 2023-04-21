/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:08:40 by nmaazouz          #+#    #+#             */
/*   Updated: 2022/10/25 08:40:38 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((char )c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

// int	main()
// {
// 	printf("min %d\n", (char )1024);
// 	printf("theim %s", strchr("teste", 1024));
// 	printf("min %s\n", ft_strchr("teste", 1024));
// 	printf("theim %s", strchr("teste", 1024));
// }