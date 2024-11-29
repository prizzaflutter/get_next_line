#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *concatenate_str(char const *s1, char const *s2)
{
    char *str;
    size_t length;
    size_t i;
    size_t j;

    if (s1 == NULL && s2 == NULL)
        return (NULL);
    if (s1 == NULL)
        return strdup(s2);
    else if (s2 == NULL)
        return strdup(s1);
    else
        length = strlen(s1) + strlen(s2);

    str = (char *)malloc((length + 1) * sizeof(char));
    if (str == NULL)
        return (NULL);

    i = 0;
    while (s1 != NULL && s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }

    j = 0;
    while (s2 != NULL && s2[j] != '\0')
        str[i++] = s2[j++];
    str[i] = '\0';
    return (str);
}

int	find_new_line (char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		
		if(str[i] == '\n')
			return(i);
		i++;
	}
	return(-1);
}

char *ft_strdup(const char *str) {
    char *copy = malloc(strlen(str) + 1);
    if (!copy) return NULL;
    strcpy(copy, str);
    return copy;
}

char *ft_strndup(const char *str, size_t n) {
    char *copy = malloc(n + 1);
    if (!copy) return NULL;
    strncpy(copy, str, n);
    copy[n] = '\0';
    return copy;
}
// int	find_new_line (char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
		
// 		if(str[i] == '\n')
// 			return(i);
// 		i++;
// 	}
// 	return(-1);
// }


// char *fix(char *remainder)
// {
// 	char *line;
// 	int find_line_index = find_new_line(remainder);
// 	if(find_line_index != -1)
// 	{
//        line = ft_strndup(remainder, find_line_index + 1);
// 			 char *new_remainder = ft_strdup(remainder + find_line_index + 1);
// 			 free(remainder);
// 			 remainder = new_remainder;
// 			 return line;
// 	}
// 	return NULL;
// }


/*
 while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) >= 0 || remainder != NULL )
    {
        buffer[bytes_read] = '\0';
        remainder = cancatenate_str(remainder, buffer);
        if (find_new_line(remainder) != -1 ) 
        {
            int new_line_index = find_new_line(remainder);
            line = ft_strndup(remainder, new_line_index + 1);
            new_remainder = ft_strdup(remainder + new_line_index + 1);
            free(remainder);
            remainder = new_remainder;
           return line;
        }
       if (bytes_read == 0 && remainder != NULL && *remainder != '\0')
        {
            line = ft_strdup(remainder);
            free(remainder);
            remainder = NULL;
            return (line);
        }
    }
*/

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }


// char *ft_strndup(const char *s, size_t len) {
//     size_t i;
//     char *result;

//     result = malloc(len + 1);  
//     if (!result) {
//         return NULL;  
//     }

//     for (i = 0; i < len; i++) {
//         result[i] = s[i];  
//     }

//     result[len] = '\0'; 
//     return result;
// }


// char *ft_strdup(const char *s1)
// {
//     if (s1 == NULL)
//         return (NULL); 

//     size_t len = ft_strlen(s1);
//     char *dst = (char *) malloc((len + 1) * sizeof(char));
//     if (dst == NULL)
//         return (NULL);

//     size_t i = 0;
//     while (s1[i])
//     {
//         dst[i] = s1[i];
//         i++;
//     }
//     dst[i] = '\0';
//     return (dst);
// }
// // void	*ft_calloc(size_t count, size_t size)
// // {
// // 	unsigned char	*tmp;

// // 	tmp = malloc(count * size);
// // 	if (tmp == NULL)
// // 		return (NULL);
// 	// ft_memset(tmp, 0, (count * size));
// // 	return (tmp);
// // }

// char *concatenate_str(char const *s1, char const *s2)
// {
//     char *str;
//     size_t length;
//     size_t i;
//     size_t j;

//     if (s1 == NULL && s2 == NULL)
//         return (NULL);
//     if (s1 == NULL)
//         length = ft_strlen(s2);
//     else if (s2 == NULL)
//         length = ft_strlen(s1);
//     else
//         length = ft_strlen(s1) + ft_strlen(s2);

//     str = (char *)malloc((length + 1) * sizeof(char));
//     if (str == NULL)
//         return (NULL);

//     i = 0;
//     while (s1 != NULL && s1[i] != '\0')
//     {
//         str[i] = s1[i];
//         i++;
//     }

//     j = 0;
//     while (s2 != NULL && s2[j] != '\0')
//         str[i++] = s2[j++];
//     str[i] = '\0';
//     return (str);
// }
// char	*ft_strchr(const char *s, int c)
// {
// 	int		i;
// 	char	ch;

// 	i = 0;
// 	ch = (char)c;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == ch)
// 			return ((char *) &s[i]);
// 		i++;
// 	}
// 	if (ch == '\0' && s[i] == '\0')
// 		return ((char *) &s[i]);
// 	return (NULL);
// }
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int	size;
// 	unsigned int	lenght;
// 	char			*substr;
// 	size_t			i;

// 	if (s == NULL)
// 		return (NULL);
// 	size = (unsigned int) ft_strlen(s);
// 	lenght = (unsigned int) len;
// 	if (start > size || size == 0)
// 		return (ft_strdup(""));
// 	if (lenght > (size - start))
// 		lenght = (size - start);
// 	substr = (char *)malloc((lenght + 1) * sizeof(char));
// 	if (substr == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < lenght)
// 	{
// 		substr[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	substr[i] = '\0';
// 	return (substr);
// }


// char *ft_get_line_from_remainder(char **remainder) {
//     char *line;
//     char *newline_pos;

//     if (*remainder == NULL)
//         return NULL;

//     newline_pos = ft_strchr(*remainder, '\n');
//     if (newline_pos) {
//         line = ft_substr(*remainder, 0, newline_pos - *remainder + 1);
//         *remainder = ft_strdup(newline_pos + 1);
//     } else {
//         line = ft_strdup(*remainder);
//         free(*remainder);
//         *remainder = NULL;
//     }

//     return line;
// }
