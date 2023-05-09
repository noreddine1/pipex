/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:19:12 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/09 22:58:31 by nmaazouz         ###   ########.fr       */
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
		ft_errorn("open_files");
	*out_file = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (*out_file < 0)
		ft_errorn("open_files");
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
