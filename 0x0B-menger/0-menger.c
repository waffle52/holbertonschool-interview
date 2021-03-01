#include "menger.h"

/**
 * menger - draws 2D sponge based off level
 * @level: level of menger sponge
 */
void menger(int level)
{
	int num, i, n, div_i, div_n;
	int let;

	num = pow(3, level);
	for (i = 0; i < num; i++)
	{
		for (n = 0; n < num; n++)
		{
			div_i = i;
			div_n = n;
			let = '#';
			while (div_i || div_n)
			{
				if (div_i % 3 == 1 && div_n % 3 == 1)
					let = ' ';
				div_i /= 3;
				div_n /= 3;
			}
			putchar(let);
		}
		printf("\n");
	}
}
