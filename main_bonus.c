#include "../get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int	open_arg(const char *arg)
{
    if (strcmp(arg, "-") == 0)
        return 0; // stdin
    return open(arg, O_RDONLY);
}

int	main(int argc, char *argv[])
{
    if (argc <= 3)
    {
        printf("Usage: %s <file1|- for stdin> <file2|- for stdin> <file3|- for stdin>\n", argv[0]);
        return (1);
    }
    printf("[Programme has started]\n\n");
    printf("Buffer size is %d\n\n", BUFFER_SIZE);
    int i = 1, j = 1, k = 1;
    char *line1, *line2, *line3;
    int fd1 = open_arg(argv[1]);
    if (fd1 < 0)
        return (1);
    printf("Opened %s with fd1 of %d\n\n", argv[1], fd1);
    int fd2 = open_arg(argv[2]);
    if (fd2 < 0)
        return (1);
    printf("Opened %s with fd2 of %d\n\n", argv[2], fd2);
    int fd3 = open_arg(argv[3]);
    if (fd3 < 0)
        return (1);
    printf("Opened %s with fd3 of %d\n\n", argv[3], fd3);

    int fd1_done = 0, fd2_done = 0, fd3_done = 0;
    printf("== BEGIN ==\n");
    while (!fd1_done || !fd2_done || !fd3_done)
    {
        if (!fd1_done && (line1 = get_next_line(fd1)))
        {
            printf("line[%d-%d] = %s", fd1, i++, line1);
            free(line1);
        }
        else if (!fd1_done)
        {
            if (line1 == NULL)
                printf("null\n");
            if (fd1 > 0)
                close(fd1);
            fd1_done = 1;
        }
        if (!fd2_done && (line2 = get_next_line(fd2)))
        {
            printf("line[%d-%d] = %s", fd2, j++, line2);
            free(line2);
        }
        else if (!fd2_done)
        {
            if (line2 == NULL)
                printf("null\n");
            if (fd2 > 0)
                close(fd2);
            fd2_done = 1;
        }
        if (!fd3_done && (line3 = get_next_line(fd3)))
        {
            printf("line[%d-%d] = %s", fd3, k++, line3);
            free(line3);
        }
        else if (!fd3_done)
        {
            if (line3 == NULL)
                printf("null\n");
            if (fd3 > 0)
                close(fd3);
            fd3_done = 1;
        }
        printf("\n");
    }
    printf("[Programme has completed]\n");
    return (0);
}