#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>


char *clean_and_exit (char **remainder, char **line , char** buffer)
{
    if(remainder && *remainder)
    {
        free(*remainder);
        *remainder = NULL;
    }
    if(buffer && *buffer)
    {
        free(*buffer);
        *buffer = NULL;
    }
      if(line && *line)
    {
        free(*line);
        *line = NULL;
    }
    return NULL;
}

char *get_next_line(int fd) {
    static char *remainder = NULL;
    char *buffer;
    int bytes_read = 1 ;
    char *line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX ||  read(fd, 0, 0) < 0)
        return clean_and_exit(&remainder, &line, &buffer);

    while (bytes_read) {
        buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if(bytes_read < 0)
            return clean_and_exit(&remainder, &line,  &buffer);
        buffer[bytes_read] = '\0';
        char *temp = remainder;
        remainder = concatenate_str(remainder, buffer); 
        free(temp);
        if (!remainder)
            return clean_and_exit(&remainder, &line,  &buffer);
        int new_line_index = find_new_line(remainder);
        if (new_line_index != -1) {
            line = ft_strndup(remainder, new_line_index + 1);
            if (!line) 
               return clean_and_exit(&remainder, &line,  &buffer);
            char *new_remainder = ft_strdup(remainder + new_line_index + 1);
            free(remainder);
            remainder = new_remainder;
            return line;
        }
         if (bytes_read == 0)
        {
                        if (remainder && *remainder)
            {
                line = ft_strdup(remainder);
                free(remainder);
                remainder = NULL;
                return line;
            }
            else
            {
                break;
            }
        }
    }
      
    return clean_and_exit(&remainder, &line, &buffer);;
}


//&& remainder != NULL && *remainder != '\0'
// void f()
// {
//     system("leaks a.out");
// }

// int main ()
// {
//     int fd = open("test.txt", O_RDONLY | O_CREAT , 0777);
//     char *line;
//     while((line = get_next_line(fd)) != NULL)
//        {
//             printf("%s", line);
//             free(line);
//        }

//        atexit(f);

//     close(fd);
// }
