/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:41:28 by pshamkha          #+#    #+#             */
/*   Updated: 2024/04/25 19:56:48 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	char	*infile_name;
	char	*outfile_name;
	int		*fd;
	char	**paths;
	char	***cmds;
	int		cmds_count;
	int		pipes_count;
	int		here_doc;
	char	*delim;
	char	**envp;
}				t_pipex;

void	init_pipex(t_pipex *p, int argc, char **argv, char **envp);
void	pipex(int argc, char **argv, char **envp);
void	child_1(t_pipex *p);
void	child_mid(t_pipex *p, int cmd_no);
void	child_last(t_pipex *p);
void	execute_cmd(t_pipex *p, int cmd_no);
void	close_pipes(t_pipex *p);
void	free_pipex(t_pipex *p);

#endif
