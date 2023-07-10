#include "main.h"

/**
 * append_text_to_file - Appends text to a file.
 * @filename: The name of the file.
 * @text_content: Text to write at the end of the file.
 * Return: 1 on success and -1 on failure
 *         If filename is NULL return -1
 *         If text_content is NULL, do not add anything to the file.
 *         Return 1 if the file exists and -1
 *         If the file does not exist or if you do not have
 *         the required permissions to write the file
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	bytes = write(fd, text_content, len);

	if (fd == -1 || bytes == -1)
		return (-1);

	close(fd);

	return (1);
}
