#include <stdio.h>

int main(void)
{
	int Tableau[] = {1, 100, 200, 300, 400};

	size_t i;

	for (i = sizeof(Tableau) / sizeof(float); i > 0; --i)
	{
		printf("Tableau[%zd] = %d\n", i - 1, Tableau[i - 1]);
	}

	return 0;
}
