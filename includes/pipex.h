/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:18:33 by juasanto          #+#    #+#             */
/*   Updated: 2021/09/10 13:19:16 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*
** Libraries
*/
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

# define READ 0
# define WRITE 1

/*
* Pipex Apoyo a los PID
*/
typedef struct s_pid
{
	pid_t		pid_c1;
	pid_t		pid_c2;
}				t_pid;
/*
* Pipex General
*/
typedef struct s_pip
{
	int			argc;
	char		**argv;
	char		**envp;
	char		**env_paths;
	char		*infile;
	char		*outfile;
	int			fd_infile;
	int			fd_outfile;
	FILE		*original_stdout;
	int			fd[2];
	t_pid		pid;
}				t_pip;
/*
* Funtions
*/
void	*ft_calloc(size_t num, size_t size);
void	ft_msgerror(char *str, int error);
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_clean(char *s1, char *s2, int clean);
void	ft_freematrice(char ***matrice);
void	ft_free_struct(t_pip *pip);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	open_files(t_pip *pip);
void	env_paths(t_pip *pip, char **envp);
t_pip	*init_pip(t_pip *pip, int argc, char **argv, char **envp);
void	child_1(t_pip *pip);
void	child_2(t_pip *pip);

#endif