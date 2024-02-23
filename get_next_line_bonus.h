#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_and_save(int fd, char *save);
char	*get_result(char *save);
char	*cut_save(char *save);
size_t	ft_strlen(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#endif
