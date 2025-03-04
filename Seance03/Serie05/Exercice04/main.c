#include <stdio.h>

int main(void)
{
	int Tableau[] = {1, 13, 45, 57, 234, 450};
	int nombre;
	int err;
	size_t i;
	int success = 0;

	printf("Entrez un nombre: ");

	err = scanf("%d", &nombre);
	if (err != 1)
	{
		printf("Erreur de lecture\n");
		return 1;
	}

	for (i = 0; i < sizeof(Tableau) / sizeof(int); ++i)
	{
		if (Tableau[i] == nombre)
		{
			printf("Le nombre %d est dans le tableau au rang %zd\n", nombre, i);
			success = 1;
			break;
		}
	}

	if (!success)
	{
		printf("Le nombre %d n'est pas dans le tableau\n", nombre);
	}

	return 0;
}
