#include "get_next_line.h"

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
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	const char		*sorc;
	size_t			i;

	dest = (unsigned char *) dst;
	sorc = (const char *) src;
	if (dest == NULL && sorc == NULL)
		return (dst);
	i = 0;
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;
	char	*src;
	// size_t		len;
	// len = ft_strlen(s1) + 1;
	src = (char *)s1;
	dst = (char *) malloc (n + 1);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, n + 1);
	return (dst);
}
char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*src;
	size_t		len;
	len = ft_strlen(s1) + 1;
	src = (char *)s1;
	dst = (char *) malloc (len );
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, len );
	return (dst);
}

char	*cancatenate_str(char const *s1, char const *s2)
{
	char	*str;
	size_t	lenght;
	size_t	i;
	size_t	j;

	if (s1 == NULL &&   s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		lenght = ft_strlen(s2);
	else if (s2 == NULL)
		lenght = ft_strlen(s1);
	else 
		lenght = (ft_strlen(s1) + ft_strlen(s2));
	str = (char *)malloc((lenght + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && i < lenght)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}