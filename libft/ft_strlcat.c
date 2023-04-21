/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:09:54 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/03/17 16:04:50 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	j;
	int	dst_size;
	int	src_size;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	i = 0;
	j = ft_strlen(dst);
	src_size = ft_strlen(src);
	dst_size = j;
	if (!dstsize || dst_size >= dstsize)
		return (src_size + dstsize);
	while (src[i] && i < dstsize - dst_size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (src_size + dst_size);
}
// #include <string.h>
// int	main()
// {
// 	char b[0xF] = "nyan !";

// 	printf("%d" ,strlcat(((void *)0), b, 0));
// }