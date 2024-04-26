/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshamkha <pshamkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:26:33 by pshamkha          #+#    #+#             */
/*   Updated: 2024/04/23 16:29:01 by pshamkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *file, char *buff)
{
	char	*tmp;

	tmp = ft_strjoin(file, buff);
	free(file);
	return (tmp);
}

char	*get_file(int fd, char *file)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (file == NULL)
		file = ft_strdup("");
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		file = join_free(file, buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (file);
}

char	*get_linef(char *file)
{
	char	*line;
	int		i;

	i = 0;
	if (file[0] == '\0')
		return (NULL);
	while (file[i] != '\0' && file[i] != '\n')
		++i;
	line = (char *) malloc((i + 2) * sizeof(char));
	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
	{
		line[i] = file[i];
		++i;
	}
	if (file[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*set_file(char *file)
{
	int		i;
	int		j;
	char	*new_file;

	i = 0;
	while (file[i] != '\0' && file[i] != '\n')
		++i;
	if (file[i] == '\0')
	{
		free(file);
		return (NULL);
	}
	new_file = (char *) malloc((ft_strlen(file) - i + 1) * sizeof(char));
	++i;
	j = 0;
	while (file[i] != '\0')
		new_file[j++] = file[i++];
	new_file[j] = '\0';
	free(file);
	return (new_file);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(file);
		file = NULL;
		return (NULL);
	}
	file = get_file(fd, file);
	if (file == NULL)
		return (NULL);
	line = get_linef(file);
	file = set_file(file);
	return (line);
}
