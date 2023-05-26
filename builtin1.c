#include "shell.h"

/**
 * _myhistory -It displays the history list,one command by line
 * preceds with line numbers beginning with 0
 * @inf:The structure contains potential arguments,It is used to
 * maintain constant function of prototypes.
 * Returns:0
 */

int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
 * unset_alias-It sets the alias to the string.
 * @info:It is the paremeter structure.
 * @str:It is the string alias.
 * Returns:0 if successful and 1 if there is an error
 */

int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;

p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}

/**
 * set_alias-It sets the alias to the string.
 * @info:It is the paremeter structure.
 * @str:its the string to the alias.
 * Returns:0 if successful and 1 if there is an error.
 */

int set_alias(info_t *info, char *str)
{
char *p;

p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias-It prints an alias string'
 * @node-Its the alias node
 * Returns:if successful and 1 if there is an error.
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias-It imitates the builtin alias.
 * @info:The structure contains potential arguments,It is used to
 * maintain constant function of prototypes
 * Returns:0
 */

int _myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}
