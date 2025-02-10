#include <stdio.h>

int main(void)
{
	int Tableau[] = {1, 100, 200, 300, 400, 800, 1000, 1200};

	size_t i;
	size_t numElements = sizeof(Tableau) / sizeof(int);
	int temp;
	for (i = 0; i < numElements / 2; ++i)
	{
		temp = Tableau[i];
		Tableau[i] = Tableau[(numElements - 1) - i];
		Tableau[(numElements - 1) - i] = temp;
	}

	for (i = 0; i < sizeof(Tableau) / sizeof(int); ++i)
	{
		printf("Tableau[%zd] = %d\n", i, Tableau[i]);
	}

	return 0;
}
