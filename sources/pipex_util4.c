/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:30:16 by juasanto          #+#    #+#             */
/*   Updated: 2021/09/10 12:38:08 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	open_files(t_pip *pip)
{
	pip->fd_outfile = open(pip->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	pip->fd_infile = open(pip->infile, O_RDONLY);
	if (pip->fd_outfile <= 0 || pip->fd_infile <= 0)
	{
		perror("Error in Files");
		exit(-131);
	}
}

void	child_1(t_pip *pip)
{
	close(pip->fd[READ]);
	dup2(pip->fd_infile, STDIN_FILENO);
	dup2(pip->fd[WRITE], STDOUT_FILENO);
	close(pip->fd[WRITE]);
}

void	child_2(t_pip *pip)
{
	close(pip->fd[WRITE]);
	dup2(pip->fd[READ], STDIN_FILENO);
	dup2(pip->fd_outfile, STDOUT_FILENO);
	close(pip->fd[READ]);
}

void	env_paths(t_pip *pip, char **envp)
{
	int		cnt;

	cnt = 0;
	if (!*envp)
	{
		perror("PATH not found");
		exit (-1);
	}
	while (ft_strncmp("PATH=", envp[cnt], 5) != 0)
		cnt++;
	pip->env_paths = ft_split(&envp[cnt][5], ':');
	cnt = -1;
	while (pip->env_paths[++cnt] != NULL)
		pip->env_paths[cnt] = ft_strjoin_clean(pip->env_paths[cnt], "/", 1);
}

t_pip	*init_pip(t_pip *pip, int argc, char **argv, char **envp)
{
	pip = ft_calloc(1, sizeof(t_pip));
	pip->argc = argc;
	pip->argv = argv;
	pip->envp = envp;
	pip->infile = pip->argv[1];
	pip->outfile = pip->argv[pip->argc - 1];
	env_paths(pip, envp);
	return (pip);
}
