/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:56:16 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/25 08:22:16 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
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
void	lk()
{
	system("leaks pipes");
}

void	open_files(char **av, int ac, t_pipe *pipe)
{
	pipe->in_file = open(av[1], O_RDONLY);
	if (pipe->in_file < 0)
		ft_error(NULL, errno);
	pipe->out_file = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipe->out_file < 0)
		ft_error(NULL, errno);
}

char	*ft_get_cmd_path(char *cmd, t_pipe pipex)
{
	char	*command;
	char	**paths;

	// puts("hello");
	paths = ft_split(pipex.path_env, ':');
	if (paths == NULL)
		ft_error("error", errno);
	if (cmd && ft_strchr(cmd, '/') != 0)
		if (access(cmd, F_OK) == 0)
			return (cmd);
	while (*paths)
	{
		command = ft_strjoin_ch(*paths, cmd, '/');
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	execute(t_pipe pipex, char **av, char **env, int type)
{
	if (type == in)
	{
		dup2(pipex.pipe_fd[1], 1);
		close(pipex.pipe_fd[0]);
		dup2(pipex.in_file, 0);
		pipex.cmd_and_flags = ft_split(av[2], ' ');
	}
	else
	{
		dup2(pipex.pipe_fd[0], 0);
		close(pipex.pipe_fd[1]);
		dup2(pipex.out_file, 1);
		pipex.cmd_and_flags = ft_split(av[3], ' ');
	}
	pipex.cmd_path = ft_get_cmd_path(pipex.cmd_and_flags[0], pipex);
	if (pipex.cmd_path == NULL)
		ft_error("Command not found", errno);
	execve(pipex.cmd_path,  pipex.cmd_and_flags, env);
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
