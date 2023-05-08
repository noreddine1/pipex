/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:53:15 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/08 18:29:16 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

// void	mltiple_execute(t_program_args *pr_args, char **paths, int i)
// {
// 	int	*pids;
// 	int	size;

// 	size = pr_args->ac - i - 1;
// 	pids = ft_calloc(size, sizeof(int));
// 	while (i < pr_args->ac - 2)
// 	{
// 		pids[i] = redirecte(pr_args->av[i], pr_args->env, paths);
// 		i++;
// 	}
// 	int last_pid = fork();
// 	if (last_pid == 0) 
// 		execute(pr_args->av[i], pr_args->env, paths);
// 	int j = 0;
// 	pids[i++] = last_pid;
// 	while (j < i) {
// 		waitpid(pids[j++], NULL, 0);
// 	}
// }

int	main(int ac, char **av, char **env)
{
	int		fd_in;
	int		fd_out;
	char	*path_env;
	char	**paths;
	int		i;
	pid_t pids[1024] = {0};
	if (ac < 5)
		ft_errorn("main");
	i = 2;
	if (ft_strncmp(av[0], "here_doc", 9) == 0)
		i = open_doc(av, ac, &fd_in, &fd_out);
	else
		open_files(av, ac, &fd_in, &fd_out);
	path_env = get_path(env);
	if (path_env == NULL)
		ft_error("path env not found");
	paths = ft_split(path_env, ':');
	if (paths == NULL)
		ft_error("split error");
	ft_dup2(fd_in, std_in);
	ft_dup2(fd_out, std_out);
	while (i < ac - 2)
	{
		pids[i] = redirecte(av[i], env, paths);
		i++;
	}
	int last_pid = fork();
	if (last_pid == 0)
		execute(av[i], env, paths);
	pids[i++] = last_pid;
	int j = 0;
	while (j < i) {
		waitpid(pids[j++], NULL, 0);
	}
	return 0;
}
