#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000
#endif

char *get_next_line(int fd);
char	*concatenate_str(char const *s1, char const *s2);
int	find_new_line (char *str);
char *ft_strndup(const char *s1, size_t n);
char	*ft_strdup(const char *s1);
// void	*ft_memset(void *ptr, int c, size_t len);
// void	*ft_calloc(size_t count, size_t size);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strchr(const char *s, int c);
// char *ft_get_line_from_remainder(char **remainder);
// char *fix(char *remainder);
#endif