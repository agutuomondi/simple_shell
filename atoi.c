#include "shell.h"

/**
 * interactive - returns  code to be true if shell is in interactive mode
 * @info: the structure address
 *
 * Return: if interactive in  mode return 1, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: character  to check
 * @delim: delimeter string
 * Return: if true return 1, if false return 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: if c is alphabetic return 1, otherwise return 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts the  string to an integer
 * @s: string to be converted
 * Return:  if no numbers in string return 0,  otherwise converted number 
 */

int _atoi(char *s)
{
	int k, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (k = 0; s[k] != '\0' && flag != 2; k++)
	{
		if (s[k] == '-')
			sign *= -1;

		if (s[k] >= '0' && s[k] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[k] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

