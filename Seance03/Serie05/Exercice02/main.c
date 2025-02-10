#include <stdio.h>

int main(void)
{
	int Tableau[11];
	size_t i;

	for (i = 0; i < 11; ++i)
	{
		Tableau[i] = (int)i * 5;
	}

	for (i = 0; i < 11; ++i)
	{
		printf("Tableau[%zd] = %d\n", i, Tableau[i]);
	}

	return 0;
}
