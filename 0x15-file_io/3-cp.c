#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of argument strings.
 *
 * Return: 0 on success, or the corresponding error code on failure.
*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd, wr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97); /* Exit with code 97 for incorrect arguments */
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98); /* Exit with code 98 for file read error */
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99); /* Exit with code 99 for file write error */
	}

	while ((rd = read(fd_from, buffer, 1024)) > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99); /* Exit with code 99 for file write error */
		}
	}

	if (rd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		exit(98); /* Exit with code 98 for file read error */
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", (close(fd_from) == -1) ? fd_from : fd_to);
		exit(100); /* Exit with code 100 for file descriptor close error */
	}

	return (0);
}
