#include <stdio.h>

int main(void)
{
	int Tableau1[5];
	int Tableau2[5];

	int err;

	size_t i;
	for (i = 0; i < sizeof(Tableau1) / sizeof(float); ++i)
	{
		printf("Entrez le nombre %zd: ", i + 1);
		err = scanf("%d", &Tableau1[i]);
		if (err != 1)
		{
			printf("Erreur de lecture\n");
			return 1;
		}

		Tableau2[sizeof(Tableau1) / sizeof(float) - i - 1] = Tableau1[i];
	}

	printf("Tableau1:\n");
	for (i = 0; i < sizeof(Tableau1) / sizeof(float); ++i)
	{
		printf("%d\t", Tableau1[i]);
	}

	printf("\nTableau2:\n");
	for (i = 0; i < sizeof(Tableau2) / sizeof(float); ++i)
	{
		printf("%d\t", Tableau2[i]);
	}

	return 0;
}
