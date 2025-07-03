#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // for open

int	main(int argc, char *argv[])
{
    int fd1;
    int i = 1;
    char *line1;

    printf("[Programme has started]\n\n");
    printf("Buffer size is %d\n\n", BUFFER_SIZE);

    if (argc > 1)
    {
        fd1 = open(argv[1], O_RDONLY);
        if (fd1 < 0)
            return (1);
        printf("Opened %s with fd1 of %d\n\n", argv[1], fd1);
    }
    else
    {
        fd1 = 0; // stdin
        printf("Reading from stdin (fd1 = 0)\n\n");
    }

    //fd1 = 42;
    //fd1 = -42;
    printf("== BEGIN ==\n");
    while ((line1 = get_next_line(fd1)) != NULL)
    {
        printf("line[%d - %d] = %s", fd1, i++, line1);
        free(line1);
    }
    printf("null\n");
    if (fd1 != 0)
        close(fd1);
    printf("[Programme is complete]\n");
    return (0);
}