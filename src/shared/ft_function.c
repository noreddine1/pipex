/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:19:54 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/09 22:21:51 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fork(int *pid)
{
	*pid = fork();
	if (*pid == -1)
		ft_errorn("ft_fork");
}

void	ft_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		ft_errorn("ft_dupe2");
	close(fd1);
}

void	ft_pipe(int *fd)
{
	if (pipe(fd) == -1)
		ft_errorn("ft_pipe");
}
