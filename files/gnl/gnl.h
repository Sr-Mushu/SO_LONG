#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 18

char	*get_next_line(int fd);

size_t	ft_strlen_gnl(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup_gnl(const char *s);
char	*ft_strchr(const char *s, int c);

#endif