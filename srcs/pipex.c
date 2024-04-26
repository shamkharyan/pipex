/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:53:09 by pshamkha          #+#    #+#             */
/*   Updated: 2024/04/26 15:56:20 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	wait_free(t_pipex *p)
{
	close_pipes(p);
	while (1)
		if (wait(NULL) == -1)
			break ;
	free_pipex(p);
}

static void	pipex_handle(t_pipex *p)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < p->cmds_count)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("pipex");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (i == 0)
				child_1(p);
			else if (i < p->pipes_count)
				child_mid(p, i);
			else
				child_last(p);
		}
		if (i == 0 && p->here_doc)
			wait(NULL);
	}
}

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex	p;

	init_pipex(&p, argc, argv, envp);
	pipex_handle(&p);
	wait_free(&p);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 6
		|| (argc == 5 && ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]))))
		pipex(argc, argv, envp);
	else
	{
		ft_putstr_fd("pipex: Bad arguments\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
