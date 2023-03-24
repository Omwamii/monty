#include "monty.h"

/**
 * check_ascii - finds if a string contains any non-number
 * @str: string to check
 *
 * Return: 0 if not found, -1 if found
 */

int check_ascii(char *str)
{
	int i = 0;
	char nums[] = "0123456789";

	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			continue;
		}
		if (!(strchr(nums, str[i])))
			return (-1);
		i++;
	}
	return (0);
}
