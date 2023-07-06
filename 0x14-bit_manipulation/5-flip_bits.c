#include "main.h"

/**
 * flip_bits - that returns the number of bits you would,
 * need to flip to get from one number to another.
 * @n: first number
 * @m: second number
 * Return: the number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count_num = 0;
	unsigned long int current;
	unsigned long int ex = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = ex >> i;
		if (current & 1)
			count_num++;
	}

	return (count_num);
}
