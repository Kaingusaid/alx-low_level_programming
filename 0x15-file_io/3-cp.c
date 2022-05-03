#include "main.h"

/**
 * close_check - checks if something can be closed and conducts correct actions
 * @cl: the output of close
 * @fd: the file descriptor to be output
 * @buf: the buffer to be freed
 * @argc: the number of arguments
 * Return: No Value
 */
void close_check(int cl, int fd, char *buf, int argc)
{
	if (cl < 0)
	{
		free(buf);
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * main - Entry point
 * @argc: the number of arguments provided to the program
 * @argv: a pointer to an array of pointers that point to the arguments
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int wr, i, fd1, fd2, cl1, cl2, rd;
	char *buf;

	close_check(0, 0, NULL, argc);
	buf = malloc(sizeof(char) * (1024));
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0)
	{
		free(buf);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 00664);
	if (fd2 < 0)
	{
		free(buf);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	do {
		for (i = 0; i < 1024; i++)
			buf[i] = '\0';
		rd = read(fd1, buf, 1024);
		if (rd < 0)
		{
			cl1 = close(fd1), close_check(cl1, fd1, buf, argc);
			cl2 = close(fd2), close_check(cl2, fd2, buf, argc);
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		wr = write(fd2, buf, rd);
		if (wr < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf), exit(99);
		}
	} while (rd == 1024);
	cl1 = close(fd1), close_check(cl1, fd1, buf, argc);
	cl2 = close(fd2), close_check(cl2, fd2, buf, argc), free(buf);
	return (0);
}
