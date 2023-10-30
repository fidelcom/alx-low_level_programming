#include "main.h"

/**
 * read_textfile - function that reads a text file and prints it
 * to the POSIX standard output.
 * @filename: file to read from
 * @letters: number of letters it should read and print
 * Return:  actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int desc;
	ssize_t reader, wrotes;
	char *bf;

	if (filename == NULL)
		return (0);

	desc = open(filename, O_RDONLY);
	if (desc == -1)
		return (0);

	bf = malloc(sizeof(char) * letters);
	if (bf == NULL)
		return (0);

	reader = read(desc, bf, letters);
	if (reader == -1)
	{
		free(bf);
		close(desc);
		return (0);
	}

	wrotes = write(STDOUT_FILENO, bf, reader);
	if (wrotes == -1)
	{
		free(bf);
		close(desc);
		return (0);
	}

	close(desc);
	return (reader);

}
