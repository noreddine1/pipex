/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:53:15 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/05 17:04:16 by nmaazouz         ###   ########.fr       */
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
	open_files(av, ac, &fd_in, &fd_out);
	path_env = get_path(env);
	if (path_env == NULL)
		ft_error("path env not found");
	paths = ft_split(path_env, ':');
	if (paths == NULL)
		ft_error("split error");
	ft_dup2(fd_in, std_in);
	ft_dup2(fd_out, std_out);
	i = 2;
	while (i < ac - 2)
	{
		redirecte(av[i], env, paths);
		i++;
	}
	execute(av[i], env, paths);
	return 0;
}
