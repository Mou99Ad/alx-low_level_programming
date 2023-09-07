#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: A NULL-terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_result;
	ssize_t text_len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	/* Open the file for appending, creating if necessary */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* Calculate the length of the text content */
	while (text_content[text_len])
		text_len++;

	/* Write the text content to the end of the file */
	write_result = write(fd, text_content, text_len);

	/* Close the file */
	close(fd);

	if (write_result == -1)
		return (-1);

	return (1);
}
