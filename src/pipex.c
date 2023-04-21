/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:56:16 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/21 00:53:40 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
/*
----parsing
-
-
-
-----execution
-fork
*/
// TODO:PARSING
/**
 * [] open files(input_file), if out_file not existe create it
 * [x] get the path from env
 * [] check the command
*/
// TODO:EXECUTION
/**
 * [] Create a child process for each command
 * [] duplicate input and output file
 *  -
 * 
*/

void	open_files(char **av, int ac, t_pipe *pipe)
{
	pipe->in_file = open(av[1], O_RDONLY);
	if (pipe->in_file < 0)
		ft_error(ERR_IN_FILE);
	pipe->out_file = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipe->out_file < 0)
		ft_error(ERR_OUT_FILE);
}

// void	execute(t_pipe pipex, char **av, char **env, int type)
// {
// 	if (type == in)
// 	{
// 		dup2(pipex.pipe_fd[0], 0);
// 		close(pipex.pipe_fd[1]);
// 		dup2(pipex.in_file, 1);
// 	}
// }

int main(int ac, char **av, char **env)
{
	t_pipe	pipex;

	(void) av;
	if (ac != 5)
		ft_error(ERR_ARGS);
	open_files(av, ac, &pipex);
	if (pipe(pipex.pipe_fd) < 0)
		ft_error("Error pipe");
	pipex.full_path = get_path(env);
	if (pipex.full_path == NULL)
		ft_error("error");
	pipex.pid1 = fork();
	// if (pipex.pid1 == 0)
	// 	execute(pipex, av, env, in);
	return 0;
}
