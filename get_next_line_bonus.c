#include "get_next_line.h"

char	*cut_save(char *save)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	while (save[i])
		tmp[j++] = save[i++];
	tmp[j] = '\0';
	free(save);
	return (tmp);
}

char	*get_result(char *save)
{
	char	*result;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		result[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		result[i] = save[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buf;
	int		j;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	j = 1;
	while (!ft_strchr(save, '\n') && j != 0)
	{
		j = read(fd, buf, BUFFER_SIZE);
		if (j == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[j] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[257];
	char		*result;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (0);
	save[fd] = ft_read_and_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	result = get_result(save[fd]);
	save[fd] = cut_save(save[fd]);
	return (result);
}
