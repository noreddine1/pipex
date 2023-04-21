/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:21:45 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/20 20:08:03 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct s_pipe
{
	pid_t	pid1;
	pid_t	pid2;
	int		in_file;
	int		out_file;
	int		pipe_fd[2];
	char	*full_path;
	char	**paths_of_cmds;
	char	*cmd;
}	t_pipe;

enum e_in_out{in, out};

# define ERR_IN_FILE "Error infile"
# define ERR_OUT_FILE "Error outfile"
# define ERR_ARGS "Invalid args"

char	*get_path(char **env);

//--error.c
void	ft_error(char *msg);

#endif