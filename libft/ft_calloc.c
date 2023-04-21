/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:39:47 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/08 16:02:17 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	void	*ptr;
	int		all_size;

	all_size = count * size;
	ptr = malloc (all_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, all_size);
	return (ptr);
}
