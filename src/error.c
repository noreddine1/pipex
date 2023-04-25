/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:32:07 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/24 21:46:22 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg, int error)
{
	if (msg)
	{
		perror(msg);
		exit(1);
	}
	perror(strerror(error));
	exit(error);
}
