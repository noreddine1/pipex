/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:56:16 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/09 23:12:15 by nmaazouz         ###   ########.fr       */
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

int	main(int ac, char **av, char **env)
{
	int		fd_in;
	int		fd_out;
	char	*path_env;
	char	**paths;

	if (ac != 5)
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
	mlt_execute(av + 2, ac - 3, env, paths);
	free_split(paths);
	return (0);
}
