#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

// char *get_next_line(int fd)
// {
//     static char *remainder = NULL;
//     char buffer[BUFFER_SIZE + 1];
//     int bytes_read;
//     char *line = NULL;
//         if (fd < 0)
//          return NULL;
//     while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0 || remainder != NULL )
//     {

//         printf("-----------------------------------\n");
//         printf("bytes_read : %d\n", bytes_read);
//         buffer[bytes_read] = '\0';
//         printf("Buffer: [%s]\n", buffer); 

//         printf("-----------------------------------\n");

//         char *tmp = cancatenate_str(remainder, buffer);
//         printf("Concatenated: [%s]\n", tmp);

//         printf("-----------------------------------\n");

//         free(remainder);
//         remainder = tmp;
//         printf("reaminder = tmp : [%s]\n", remainder);

//         printf("-----------------------------------\n");

//         int new_line_index = find_new_line(remainder);
//         printf("Newline index: %d\n", new_line_index); 

//         printf("-----------------------------------\n");
       
//         while (find_new_line(remainder) != -1) 
//         {
//             int new_line_index = find_new_line(remainder);
//             line = strndup(remainder, new_line_index );
//             printf("Line to return: ==========>  [%s] <===========n", line); 

//             printf("-----------------------------------\n");

//             char *new_remainder = strdup(remainder + new_line_index + 1);
//             printf("New remainder: [%s]\n", new_remainder); 

//             printf("-----------------------------------\n");

//             free(remainder);
//             remainder = new_remainder;
//             printf("original remainder %s\n", remainder);
//         } 
//          return line;
//     }

//     if (bytes_read == 0 && remainder)
//     {
//         line = strdup(remainder);
//         printf("-----------------------------------\n");
//         printf("Final line at EOF: [%s]\n", line); 
//         printf("-----------------------------------\n");
//         free(remainder);
//         remainder = NULL;
//         return line;
//     }

//     return NULL;
// }

// //=====================================================================================

char *get_next_line_test(int fd)
{
    static char *remainder = NULL;
    char *new_remainder = NULL;
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    char *line = NULL;
        if (fd < 0)
         return NULL;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0 || remainder != NULL)
    {
        buffer[bytes_read] = '\0';
        remainder = cancatenate_str(remainder, buffer);
        if (find_new_line(remainder) != -1 ) 
        {
            int new_line_index = find_new_line(remainder);
            line = strndup(remainder, new_line_index + 1);
            new_remainder = strdup(remainder + new_line_index + 1);
            free(remainder);
            remainder = new_remainder;
           return line;
        }
       if (bytes_read == 0 && remainder != NULL && *remainder != '\0')
        {
        line = strdup(remainder);
        free(remainder);
        remainder = NULL;
        return line;
        } 
    }

    
    return NULL;
}



int main ()
{
	int fd = open("askour.txt", O_RDWR | O_CREAT, 0777);
	printf("%d\n", fd);
    char *str = get_next_line_test(fd);
    printf("%s\n", str);
    printf("-----askour------\n");
    char *st = get_next_line_test(fd);
    printf("%s\n", st);
     char *s = get_next_line_test(fd);
    printf("%s\n", s);
     char *t = get_next_line_test(fd);
    printf("%s\n", t);
  close(fd);
	return 0;
}
