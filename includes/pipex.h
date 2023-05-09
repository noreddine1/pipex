/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:21:45 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/05/09 22:23:02 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_pipe
{
	pid_t	pid1;
	pid_t	pid2;
	int		in_file;
	int		out_file;
	int		pipe_fd[2];
	char	*path_env;
	char	**cmd_and_flags;
	char	*cmd_path;
}	t_pipe;

enum e_std{std_in, std_out};

# define ERR_IN_FILE "Error infile"
# define ERR_OUT_FILE "Error outfile"
# define ERR_ARGS "Invalid args"

char	*get_path(char **env);

//---ft_function.c
void	ft_fork(int *pid);
void	ft_dup2(int fd1, int fd2);
void	ft_pipe(int *fd);

//--error.c
void	ft_error(char *msg);
void	ft_errorn(char *fuction_name);

//here_doc.c
int		open_doc(char **av, int ac, int *fd_in, int *fd_out);

//--utils.c
void	open_files(char **av, int ac, int *fd_in, int *fd_out);
char	*ft_get_cmd_path(char *cmd, char **paths);
void	execute(char *av, char **env, char **paths);
int		redirecte(char *av, char **env, char **paths);

#endif