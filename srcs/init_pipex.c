/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:28:40 by pshamkha          #+#    #+#             */
/*   Updated: 2024/04/25 19:07:57 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_paths(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		++i;
	return (ft_split(envp[i] + 5, ':'));
}

static int	init_first(t_pipex *p, int argc, char **argv, char **envp)
{
	int	i;

	p->infile_name = argv[1];
	p->outfile_name = argv[argc - 1];
	if (!ft_strncmp(p->infile_name, "here_doc", ft_strlen(p->infile_name)))
	{
		p->here_doc = 1;
		p->delim = argv[2];
	}
	p->envp = envp;
	p->cmds_count = argc - 3 - p->here_doc;
	p->pipes_count = argc - 4 - p->here_doc;
	p->fd = (int *) malloc(sizeof(int) * 2 * (p->pipes_count));
	if (p->fd == NULL)
		return (1);
	i = 0;
	while (i < 2 * (p->pipes_count))
	{
		if (pipe(p->fd + i) < 0)
			return (1);
		i += 2;
	}
	return (0);
}

static int	init_second(t_pipex *p, char **argv, char **envp)
{
	int	i;

	p->paths = get_paths(envp);
	if (p->paths == NULL)
		return (1);
	p->cmds = (char ***) malloc(sizeof(char **) * (p->cmds_count));
	if (p->cmds == NULL)
		return (1);
	i = -1;
	while (++i < p->cmds_count)
	{
		p->cmds[i] = ft_split(argv[i + 2 + p->here_doc], ' ');
		if (p->cmds[i] == NULL)
			return (1);
	}
	return (0);
}

void	init_pipex(t_pipex *p, int argc, char **argv, char **envp)
{
	p->fd = NULL;
	p->paths = NULL;
	p->cmds = NULL;
	p->here_doc = 0;
	p->delim = NULL;
	if (init_first(p, argc, argv, envp))
	{
		free_pipex(p);
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	if (init_second(p, argv, envp))
	{
		free_pipex(p);
		perror("pipex");
		exit(EXIT_FAILURE);
	}
}
