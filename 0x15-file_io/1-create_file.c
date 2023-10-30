#include "main.h"

/**
 * _strlen - find length of a string
 * @str: string
 * Return: length
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;

	return (len);
}

/**
 * create_file - function creates file with permissions rw------- and writes
 * content in if file already exists, don't change permissions and
 * just truncate it
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 * Return: 1 on success, -1 on error
 */
int create_file(const char *filename, char *text_content)
{
	int desc;
	int wrotes;

	if (!filename)
		return (-1);

	desc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (desc == -1)
		return (-1);

	if (!text_content)
	{
		close(desc);
		return (1);
	}

	wrotes = write(desc, text_content, _strlen(text_content));
	if (wrotes == -1 || wrotes != _strlen(text_content))
	{
		close(desc);
		return (-1);
	}

	close(desc);
	return (1);
}
