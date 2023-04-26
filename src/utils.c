/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:19:12 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/26 08:52:18 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

char	*get_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env,"PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
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
