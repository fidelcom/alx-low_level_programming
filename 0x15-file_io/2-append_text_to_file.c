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
 * append_text_to_file - function that appends text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 * Return: 1 on success, -1 on error
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int desc;
	int wrotes;

	if (!filename)
		return (-1);

	desc = open(filename, O_WRONLY | O_APPEND);
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
