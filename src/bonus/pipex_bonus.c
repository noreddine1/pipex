/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:53:15 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/14 19:29:22 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd_in;
	int		fd_out;
	char	*path_env;
	char	**paths;
	int		i;

	i = 2;
	if (ac < 5)
		ft_errorn("main");
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
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
	mlt_execute(av + i, ac - i - 1, env, paths);
	free_split(paths);
	exit(EXIT_SUCCESS);
}
