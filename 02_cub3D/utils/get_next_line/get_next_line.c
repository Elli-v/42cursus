/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 19:25:36 by soooh             #+#    #+#             */
/*   Updated: 2021/06/17 15:20:20 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int find_n(char *backup, int flag)
{
	int i;

	i = 0;
	while (backup[i])
	{
		if (flag == 1)
		{
			if (backup[i] == '\n' || backup[i] == '\r')
				return (i);
		}
		else
		{
			if (backup[i] == '\n')
				return (i);
		}
		i++;
	}

	return (-1);
}

int div_line(char **backup, char **line, int idx_num)
{
	char *temp;
	int len;

	(*backup)[idx_num] = '\0';
	*line = gnl_strdup(*backup);
	len = gnl_strlen(*backup + idx_num + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = gnl_strdup(*backup + idx_num + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int onandon(char **backup, char **line, int save_str, int flag)
{
	int idx_num;

	if (save_str < 0 || !backup)
		return (-1);
	if (*backup && (idx_num = find_n(*backup, flag)) >= 0)
		return (div_line(backup, line, idx_num));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = gnl_strdup("");

	return (0);
}

int get_next_line(int fd, char **line, int flag)
{
	char buffer[BUFFER_SIZE + 1];
	static char *backup[OPEN_MAX];
	int save_str;
	int idx_num;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((save_str = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[save_str] = '\0';
		backup[fd] = gnl_strjoin(backup[fd], buffer);
		if ((idx_num = find_n(backup[fd], flag)) >= 0)
			return (div_line(&backup[fd], line, idx_num));
	}
	return (onandon(&backup[fd], line, save_str, flag));
}
