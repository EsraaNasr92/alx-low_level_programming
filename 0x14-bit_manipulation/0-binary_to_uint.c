#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int.
 * @b: string containing the binary number
 * Return: the converted number, or 0 or 1 or NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec_value = 0;
	int i;

	if (b == 0)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		dec_value = 2 * dec_value + (b[i] - '0');
	}

	return (dec_value);
}
