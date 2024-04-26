/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:53:28 by pshamkha          #+#    #+#             */
/*   Updated: 2024/04/26 15:11:08 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_script(t_pipex *p, int cmd_no)
{
	char	*temp;
	char	**args;
	int		i;

	if (ft_strchr(p->cmds[cmd_no][0], '/') != NULL
		&& access(p->cmds[cmd_no][0], F_OK | X_OK) != -1)
	{
		temp = ft_strjoin("/bin/bash ", p->cmds[cmd_no][0]);
		args = ft_split(temp, ' ');
		free(temp);
		execve("/bin/bash", args, p->envp);
		i = 0;
		while (args[i] != NULL)
			free(args[i++]);
		perror("pipex");
		exit(EXIT_FAILURE);
	}
}

void	execute_cmd(t_pipex *p, int cmd_no)
{
	int		i;
	char	*temp;
	char	*cmd;

	execute_script(p, cmd_no);
	i = 0;
	temp = ft_strjoin(p->paths[0], "/");
	cmd = ft_strjoin(temp, p->cmds[cmd_no][0]);
	free(temp);
	while (p->paths[++i] != NULL)
	{
		if (access(cmd, F_OK | X_OK) != -1)
			break ;
		free(cmd);
		temp = ft_strjoin(p->paths[i], "/");
		cmd = ft_strjoin(temp, p->cmds[cmd_no][0]);
		free(temp);
	}
	execve(cmd, p->cmds[cmd_no], p->envp);
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(p->cmds[cmd_no][0], 2);
	ft_putchar_fd('\n', 2);
	free(cmd);
	exit(EXIT_FAILURE);
}
