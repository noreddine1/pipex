/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:30:12 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/14 19:30:14 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"
#include <fcntl.h>

int	open_doc(char **av, int ac, int *fd_in, int *fd_out)
{
	const char	*file_name = "her_doc";
	char		*line;

	if (ac < 6)
		ft_error(ERR_ARGS);
	*fd_in = open(file_name, O_RDWR | O_CREAT, 0777);
	if (*fd_in < 0)
		ft_errorn("open_doc");
	*fd_out = open(av[ac - 1], O_APPEND | O_CREAT | O_RDWR, 0644);
	if (*fd_out < 0)
		ft_errorn("open_doc");
	line = get_next_line(std_in);
	while (line && ft_strncmp(av[2], line, ft_strlen(line) - 1))
	{
		write(*fd_in, line, ft_strlen(line));
		free(line);
		line = get_next_line(std_in);
	}
	close(*fd_in);
	*fd_in = open(file_name, O_RDONLY);
	unlink(file_name);
	return (3);
}
