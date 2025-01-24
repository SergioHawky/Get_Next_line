#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && BUFFER_SIZE > 0) && bytes_read > 0)
	{
		if (buff[0])
		{
			line = ft_strjoin(line, buff);
			if (!line)
				return (NULL);
			if (line[ft_strlen(line) - 1] == '\n')
				break ;
		}
		else
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			buff[bytes_read] = '\0';
		}
	}
	return (line);
}


/*int	main(void)
{
	int		fd;
	char	*line;

	// Abrir o ficheiro para leitura
	fd = open("test_file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o ficheiro");
		return (1);
	}

	// Ler e imprimir linha por linha
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line); // Libertar memória da linha retornada
	}

	// Fechar o ficheiro
	printf("\n");
	close(fd);
	return (0);
}*/

int	main(void)
{
	int		fd;
	char	*line;
	char	buffer[1024+1];
	int		read_bytes;

	(void) line;
	fd = open("test_file.txt", O_RDONLY);
	(void) read_bytes;
	buffer[1024] = '\0';
	while(!(buffer[0] == 'E' && buffer[1] == '\n'))
	{
		printf("Quer uma nova linha, de enter to Exit (E):\n");
		read_bytes = read(0,buffer,1024);
		if(buffer[0] == 'E' && buffer[1] == '\n')
			break ;
		printf("%s", get_next_line(fd));
	}
	return (0);
}