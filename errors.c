#include "shell.h"

/**
 * _eputs-This prints the input string.
 * @str:Is the string that will be printed.
 * Returns:Nothing
 */

void _eputs(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_eputchar(str[i]);
i++;
}
}

/**
 * _eputchar-This writes the character c to the standard error.
 * @c:The character that will be printed.
 * Returns:1 if successful,-1 if on error and error
 * number is appropiately set up.
 */

int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putfd-It writes the character to the given fd.
 * @c:Is the character that will be printed.
 * @fd:The filedescriptor that will be written to.
 * Returns:1 if successful,-1 if on error and error
 * number is appropiately set up.
 */

int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _putsfd -This prints an input string
 * @str:The string that will be printed
 * @fd:The filedescriptor that will be written to
 * Returns: The number of chars put
 */

int _putsfd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _putfd(*str++, fd);
}
return (i);
}

