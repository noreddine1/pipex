/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:36:16 by nmaazouz          #+#    #+#             */
/*   Updated: 2022/10/18 10:47:43 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			size_n;
	char		*str;
	long int	nb;

	size_n = ft_count(n);
	nb = n;
	str = (char *)malloc(sizeof(char) * size_n + 1);
	if (!str)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (!nb)
		str[0] = '0';
	str[size_n] = 0;
	while (nb)
	{
		str[--size_n] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
