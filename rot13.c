#include "main.h"
#include <stdlib.h>

char *_strcpy(char *dest, char *src);

int rot13(va_list args)
{
	char *normalLetters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13Letters = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str;
	int i, len;
	char *rot13Str, *ptr;
	int write_status;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		return -1; // Return some error code
	}

	len = _strlen(str);

	rot13Str = malloc(sizeof(char) * (len + 1));
	ptr = rot13Str;
	if (rot13Str == NULL)
	{
		return -1; // Return some error code if malloc failed
	}

	_strcpy(rot13Str, str);

	printf("rot13Str = %s\n", rot13Str);

	while (*rot13Str)
	{
		for (i = 0; i < 53; i++)
		{
			if (*rot13Str == normalLetters[i])
			{
				*rot13Str = rot13Letters[i];
				break;
			}
		}
		rot13Str++;
	}

	len = _strlen(ptr);
	printf("rot13: %s ,%i\n", ptr, len);

	write_status = write(1, ptr, len);

	free(ptr);

	return write_status;
}
/**
 * _strcpy - function that copies a string
 *
 * @dest: parameter of a string wanted to be copied to
 * @src: string wanted to be copy from
 *
 * Return: dest value .
 *
 */
char *_strcpy(char *dest, char *src)
{
	unsigned int i = 0;

	for (; i <= _strlen(src); i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}