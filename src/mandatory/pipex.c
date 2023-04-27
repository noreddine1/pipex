/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:56:16 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/27 16:54:50 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
void	lk()
{
	system("leaks pipex");
}

int main(int ac, char **av, char **env)
{
	t_pipe	pipex;
	int		status;

	if (ac != 5)
		ft_error(ERR_ARGS);
	open_files(av, ac, &pipex);
	if (pipe(pipex.pipe_fd) < 0)
		ft_errorn();
	pipex.path_env = get_path(env);
	if (pipex.path_env == NULL)
		ft_error("path env not found");
	ft_fork(&pipex.pid1);
	if (pipex.pid1 == 0)
		execute(pipex, av, env, in);
	ft_fork(&pipex.pid2);
	if (pipex.pid2 == 0)
		execute(pipex, av, env, out);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, &status, 0);
	return (0);
}
