#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters:  is the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 * return 0 if can't open or read
 * if file is NULL return 0 or write fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	int fd;
	ssize_t bytes;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	bytes = read(fd, buf, letters);
	bytes = write(STDOUT_FILENO, buf, bytes);

	free(buf);
	close(fd);
	return (bytes);
}
