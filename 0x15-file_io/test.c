#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * exit_error - Prints an error message and exits with the specified code.
 * @code: The exit code.
 * @msg: The error message to print.
 */
void exit_error(int code, const char *msg)
{
    dprintf(2, "%s\n", msg);
    exit(code);
}

/**
 * copy_file - Copies the content of one file to another.
 * @from: The source file descriptor.
 * @to: The destination file descriptor.
 */
void copy_file(int from, int to)
{
    char buffer[1024];
    ssize_t rd, wr;

    while ((rd = read(from, buffer, sizeof(buffer))) > 0)
    {
        wr = write(to, buffer, rd);
        if (wr == -1)
            exit_error(99, "Error: Can't write to destination file");
    }

    if (rd == -1)
        exit_error(98, "Error: Can't read from source file");
}

int main(int argc, char *argv[])
{
    int fd_from, fd_to;

    if (argc != 3)
        exit_error(97, "Usage: cp file_from file_to");

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        exit_error(98, "Error: Can't read from source file");

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
        exit_error(99, "Error: Can't write to destination file");

    copy_file(fd_from, fd_to);

    if (close(fd_from) == -1 || close(fd_to) == -1)
        exit_error(100, "Error: Can't close file descriptor");

    return (0);
}

