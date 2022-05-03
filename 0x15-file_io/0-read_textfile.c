#include "main.h"
/**
 * read_textfile - function that reads a text file
 * and prints it to the POSIX standard output.
 * @filename: input
 * @letters: is the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	int fd;
	int reading;
	int writing;

	if (filename == NULL)
	{
		return (0);
	}
	buf = malloc(letters);
	if (buf == NULL)
	{
		free(buf);
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}
	reading = read(fd, buf, letters);
	if (reading == -1)
	{
		free(buf);
		return (0);
	}
	buf[letters] = '\0';
	writing = write(STDOUT_FILENO, buf, reading);
	if (writing == -1)
	{
		free(buf);
		return (0);
	}
	free(buf);
	close(fd);
	return (writing);
}
