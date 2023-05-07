/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:53:15 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/07 18:17:59 by nmaazouz         ###   ########.fr       */
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

	if (ac < 5)
		ft_error(ERR_ARGS);
	i = 2;
	if (ft_strncmp(av[0], "here_doc", 9))
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
		redirecte(av[i++], env, paths);
	execute(av[i], env, paths);
	return (0);
}
