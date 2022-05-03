#include "main.h"

/**
 * create_file - creates a file
 * @filename: pointer to the file name
 * @text_content: a pointer to the content to be inserted into the file
 * Return: 1 on success and -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd = 0, wr = 0, len = 0;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00600);
	if (fd < 0)
		return (-1);
	if (text_content && *text_content)
	{
		while (text_content[len++])
			;
		wr = write(fd, text_content, len - 1);
		if (wr < 0)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
