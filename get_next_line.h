#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

char *get_next_line(int fd);
char	*cancatenate_str(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int	find_new_line (char *str);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif