//#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 50

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*str;
    size_t	i;
    size_t	j;

    if (!s1 || !s2)
        return (0);
    str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!str)
        return (0);
    i = 0;
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return (str);
}

char	*ft_strchr(char *str, char c)
{
	size_t	l;

	l = 0;
    if (c == '\0')
		return (&str[l]);
	while (str[l] != '\0')
	{
		if (str[l] == c)
			return (&str[l]);
		l++;
	}
	return (0);
}

char *ft_next(char *buffer)
{
    int i;
    int j;
    char *next_line;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (!buffer[i])
    {
        free(buffer);
        return (NULL);
    }
    next_line = (char *)malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
    if (!next_line)
        return (NULL);
    i++;
    j = 0;
    while (buffer[i])
        next_line[j++] = buffer[i++];
    next_line[j] = '\0';
    free(buffer);
    return (next_line);
}

char *ft_line(char *buffer)
{
    char *line;
    int i;
    if (!buffer)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = (char *)malloc((i + 2) * sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] && buffer[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char *read_file(int fd, char *buffer)
{
    char *temp;
    int bytes_read;

    if (!buffer)
        buffer = (char *)malloc(1);
    buffer[0] = '\0';
    temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!temp)
    {
        free(buffer);
        return (NULL);
    }
    temp[0] = '\0';
    bytes_read = 1;
    while (bytes_read > 0)
    { 
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(temp);
            return (NULL);
        }
        temp[bytes_read] = '\0';
        buffer = ft_strjoin(buffer, temp);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(temp);
    return (buffer);
}

char *get_next_line(int fd) {
    static  char    *buffer;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
        return (NULL);
    buffer = read_file(fd, buffer);
    if (!buffer)
        return (NULL);
    line = ft_line(buffer);
    buffer = ft_next(buffer);
    return (line);
}





int main(void) {
    int fd;
    char *buffer;
    //int i;

    fd = open("C:\\Users\\hesam\\OneDrive\\Desktop\\getnextline\\content.txt", O_RDONLY);
    
    buffer = get_next_line(fd);
    printf("%s\n", buffer);
    // buffer = get_next_line(fd);
    // printf("%s\n", buffer);
    // buffer = get_next_line(fd);
    // printf("%s\n", buffer);
    close(fd);

    return EXIT_SUCCESS;


}