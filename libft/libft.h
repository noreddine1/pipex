/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmaazouz <nmaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:56:21 by nmaazouz          #+#    #+#             */
/*   Updated: 2023/04/22 12:23:56 by nmaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_strlen(const char *s);
void		*ft_memset(void *b, int c, int len);
void		ft_bzero(void *s, int n);
void		*ft_memcpy(void *dst, const void *src, int n);
void		*ft_memmove(void *dst, const void *src, int len);
int			ft_strlcpy(char *dst, const char *src, int dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, int n);
void		*ft_memchr(const void *s, int c, int n);
int			ft_memcmp(const void *s1, const void *s2, int n);
char		*ft_strnstr(const char *haystack, const char *needle, int len);
long int	ft_atoi(const char *str);
int			ft_strlcat(char *dst, const char *src, int dstsize);
void		*ft_calloc(int count, int size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, int len);
char		*ft_strjoin_ch(char const *s1, char *s2, char c);
char		*ft_strjoin(char const *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*fsize_t)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_lst
{
	void			*content;
	struct s_lst	*next;
}	t_lst;

t_lst		*ft_lstnew(void *content);
void		ft_lstadd_front(t_lst **lst, t_lst *New);
int			ft_lstsize(t_lst *lst);
t_lst		*ft_lstlast(t_lst *lst);
void		ft_lstadd_back(t_lst **lst, t_lst *New);
void		ft_lstdelone(t_lst *lst, void (*del)(void *));
void		ft_lstclear(t_lst **lst, void (*del)(void *));
void		ft_lstiter(t_lst *lst, void (*f)(void *));
t_lst		*ft_lstmap(t_lst *lst, void *(*f)(void*), void (*del)(void *));

//----------get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  10000
# endif

char		*get_next_line(int fd);
int			ft_len(char *s);
char		*get_next_line(int fd);
int			is_new_line(char *str, int *i);

#endif
