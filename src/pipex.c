/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:56:16 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/26 08:52:14 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
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
void	lk()
{
	system("leaks pipes");
}

int main(int ac, char **av, char **env)
{
	t_pipe	pipex;
// atexit(lk);
	(void) av;
	if (ac != 5)
		ft_error(ERR_ARGS, errno);
	open_files(av, ac, &pipex);
	if (pipe(pipex.pipe_fd) < 0)
		ft_error("Error pipe", errno);
	pipex.path_env = get_path(env);
	if (pipex.path_env == NULL)
		ft_error(NULL, errno);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		execute(pipex, av, env, in);
	if (pipex.pid1 != 0)
		execute(pipex, av, env, out);
	waitpid(pipex.pid1, NULL, 0);
	return 0;
}
