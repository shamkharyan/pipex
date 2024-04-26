/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:38:03 by pshamkha          #+#    #+#             */
/*   Updated: 2024/04/26 15:51:10 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	here_doc(t_pipex *p)
{
	int		infile_fd;
	char	*line;

	infile_fd = open(p->infile_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (infile_fd < 0)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(0);
	while (ft_strncmp(line, p->delim, ft_strlen(line) - 1)
		|| (line[0] == '\n' && p->delim[0] != '\0'))
	{
		ft_putstr_fd(line, infile_fd);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(infile_fd);
}

void	child_1(t_pipex *p)
{
	int		infile_fd;

	if (p->here_doc)
		here_doc(p);
	infile_fd = open(p->infile_name, O_RDONLY);
	if (infile_fd < 0)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(p->fd[1], STDOUT_FILENO);
	close_pipes(p);
	if (p->here_doc)
		unlink(p->infile_name);
	execute_cmd(p, 0);
}

void	child_mid(t_pipex *p, int cmd_no)
{
	dup2(p->fd[2 * cmd_no - 2], STDIN_FILENO);
	dup2(p->fd[2 * cmd_no + 1], STDOUT_FILENO);
	close_pipes(p);
	execute_cmd(p, cmd_no);
}

void	child_last(t_pipex *p)
{
	int		outfile_fd;

	outfile_fd = open(p->outfile_name,
			O_WRONLY | O_CREAT | O_TRUNC * !(p->here_doc)
			| O_APPEND * (p->here_doc), 0644);
	if (outfile_fd < 0)
	{
		perror("pipex");
		exit(EXIT_FAILURE);
	}
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	dup2(p->fd[2 * (p->pipes_count) - 2], STDIN_FILENO);
	close_pipes(p);
	execute_cmd(p, p->pipes_count);
}
