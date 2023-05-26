#include "shell.h"

/**
 * *_strncpy-This copies a string
 * @dest:The destination that the string will be copied to
 * @src:The source string
 * @n:The amount of characters that will be copied
 *
 * Return: The concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *_strncat-This concatenates(joins) two strings.
 * @dest:The first string.
 * @src:The second string.
 * @n:The maximum bytes to be used.
 *
 * Return: The concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * *_strchr-This locates a character in a string
 * @s:The string that will be parsed
 * @c:The character to look out for
 *
 * Return: (s) is a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
