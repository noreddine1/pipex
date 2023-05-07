/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:19:12 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/07 18:14:34 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			return (*env + 5);
		env++;
	}
	return (NULL);
}

void	open_files(char **av, int ac, int *in_file, int *out_file)
{
	*in_file = open(av[1], O_RDONLY);
	if (*in_file < 0)
		ft_errorn();
	*out_file = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (*out_file < 0)
		ft_errorn();
}

char	*ft_get_cmd_path(char *cmd, char **paths)
{
	char	*command;

	if (cmd && ft_strchr(cmd, '/') != 0)
	{
		if (access(cmd, F_OK) == 0)
			return (cmd);
	}
	else
	{
		while (*paths)
		{
			command = ft_strjoin_ch(*paths, cmd, '/');
			if (access(command, F_OK) == 0)
				return (command);
			free(command);
			paths++;
		}
	}
	return (NULL);
}

void	execute(char *av, char **env, char **paths)
{
	char	*cmd_path;
	char	**args;

	args = ft_split(av, ' ');
	if (args == NULL)
		ft_error("Error split");
	if (args[0] == NULL)
		ft_error("command not found");
	cmd_path = ft_get_cmd_path(args[0], paths);
	if (cmd_path == NULL)
		ft_error("Command not found");
	execve(cmd_path, args, env);
}

void	redirecte(char *av, char **env, char **paths)
{
	int		fd[2];
	pid_t	pid;

	ft_pipe(fd);
	ft_fork(&pid);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], std_out);
		execute(av, env, paths);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], std_in);
		waitpid(pid, NULL, 0);
	}
}
