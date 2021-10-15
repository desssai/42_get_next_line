#ifndef __GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096

#endif /* BUFFER_SIZE */

char	*get_next_line(int fd);

#endif /* __GET_NEXT_LINE_H__ */