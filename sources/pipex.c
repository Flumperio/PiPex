/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:18:12 by juasanto          #+#    #+#             */
/*   Updated: 2021/09/10 13:22:10 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	exe_cmd(t_pip *pip, int order)
{
	int		cnt;
	char	**args;
	char	*cmd;

	cnt = -1;
	cmd = NULL;
	args = ft_split(pip->argv[order], ' ');
	if (access(args[0], R_OK) == 0)
	{
		execve(args[0], args, pip->envp);
		free(args);
	}
	else
	{
		while (pip->env_paths[++cnt] != NULL)
		{
			cmd = ft_strjoin_clean(pip->env_paths[cnt], args[0], 3);
			if (access(cmd, R_OK) == 0)
				execve(cmd, args, pip->envp);
		}
		return (-4);
	}
	return (0);
}

int	child1(t_pip *pip)
{
	pip->pid.pid_c1 = fork();
	if (pip->pid.pid_c1 < 0)
		perror(("Fork error: "));
	if (pip->pid.pid_c1 == 0)
	{
		child_1(pip);
		if (exe_cmd(pip, 2) < 0)
		{
			perror("CMD_1");
			return (-1);
		}
	}
	return (0);
}

int	child2(t_pip *pip)
{
	pip->pid.pid_c2 = fork();
	if (pip->pid.pid_c2 < 0)
		perror(("Fork error: "));
	if (pip->pid.pid_c2 == 0)
	{
		child_2(pip);
		if (exe_cmd(pip, 3) < 0)
		{
			perror("CMD_2");
			return (-1);
		}
	}
	return (0);
}

int	fn_exe_child(t_pip *pip)
{
	int		status;

	pipe(pip->fd);
	if (child1(pip) < 0)
		return (-1);
	if (child2(pip) < 0)
		return (-1);
	close(pip->fd[READ]);
	close(pip->fd[WRITE]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	*pip;

	if (argc != 5)
		ft_msgerror("Bad Parameters.", 5);
	pip = NULL;
	pip = init_pip(pip, argc, argv, envp);
	open_files(pip);
	if (fn_exe_child(pip) == 0)
	{
		ft_freematrice(&pip->env_paths);
		ft_free_struct(pip);
	}
	return (0);
}
