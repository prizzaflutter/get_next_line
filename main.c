#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


void f ()
{
    system("leaks ask");
}
void test_with_file(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return;
    }

    char *line;
    printf("Reading from file: %s\n", filename);
    while((line = get_next_line(fd)) != NULL)
    {
          printf("%s", line);
    free(line);
    }
  
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     printf("%s", line); 
    //     free(line);
    // }
    close(fd);
}

void test_with_stdin()
{
    char *line;
    printf("Reading from standard input (type lines and press Enter, Ctrl+D to stop):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("Read from stdin: %s\n", line); 
        free(line);
        line = NULL;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
       {
        atexit(f);
         test_with_file(argv[1]);
       }
    else
        test_with_stdin();
    return 0;
}