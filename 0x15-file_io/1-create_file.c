#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * create_file - Creates a file and writes text content to it.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, write_result;
	ssize_t text_len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	/* Open the file or create it if it doesn't exist */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* Calculate the length of the text content */
	while (text_content[text_len])
		text_len++;

	/* Write the text content to the file */
	write_result = write(fd, text_content, text_len);

	/* Close the file */
	close(fd);

	if (write_result == -1 || write_result != text_len)
		return (-1);

	return (1);
}
