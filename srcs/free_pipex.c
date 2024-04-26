/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:19:05 by pshamkha          #+#    #+#             */
/*   Updated: 2024/04/25 19:07:46 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmds(t_pipex *p)
{
	int	i;
	int	j;

	if (p->cmds != NULL)
	{
		i = 0;
		while (i < p->cmds_count)
		{
			if (p->cmds[i] != NULL)
			{
				j = 0;
				while (p->cmds[i][j] != NULL)
				{
					free(p->cmds[i][j]);
					p->cmds[i][j++] = NULL;
				}
				free(p->cmds[i]);
				p->cmds[i] = NULL;
			}
			++i;
		}
		free(p->cmds);
		p->cmds = NULL;
	}
}

static void	free_paths(t_pipex *p)
{
	int	i;

	if (p->paths != NULL)
	{
		i = 0;
		while (p->paths[i] != NULL)
		{
			free(p->paths[i]);
			p->paths[i++] = NULL;
		}
		free(p->paths);
		p->paths = NULL;
	}
}

void	free_pipex(t_pipex *p)
{
	free(p->fd);
	p->fd = NULL;
	free_cmds(p);
	free_paths(p);
}

void	close_pipes(t_pipex *p)
{
	int	i;

	i = 0;
	while (i < 2 * (p->pipes_count))
		close(p->fd[i++]);
}
