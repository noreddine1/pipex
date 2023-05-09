/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:58:01 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/09 23:12:36 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute(char *av, char **env, char **paths)
{
	char	*cmd_path;
	char	**args;

	args = ft_split(av, ' ');
	if (args == NULL)
		ft_error("Error split");
	if (args[0] == NULL)
	{
		ft_error("command not found");
	}
	cmd_path = ft_get_cmd_path(args[0], paths);
	if (cmd_path == NULL)
	{
		ft_putendl_fd(cmd_path, 2);
		ft_error("Command not found");
	}
	execve(cmd_path, args, env);
}

static int	redirecte(char *av, char **env, char **paths)
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
	}
	return (pid);
}

void	mlt_execute(char **av, int nbr_cmd, char **env, char **paths)
{
	int		i;
	pid_t	*pids;
	pid_t	last_pid;

	i = 0;
	pids = ft_calloc(nbr_cmd + 1, sizeof(pid_t));
	if (pids == NULL)
		ft_errorn("mlt_execute");
	while (i < nbr_cmd - 1)
	{
		pids[i] = redirecte(av[i], env, paths);
		i++;
	}
	ft_fork(&last_pid);
	if (last_pid == 0)
		execute(av[i], env, paths);
	i = 0;
	while (pids[i])
		waitpid(pids[i++], NULL, 0);
	free(pids);
}
