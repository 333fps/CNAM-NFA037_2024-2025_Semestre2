#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float* tableau;
	size_t nombreCases;
	int err;
	size_t i;

	printf("Entrez le nombre de cases du tableau: ");
	err = scanf("%zd", &nombreCases);
	if (err != 1)
	{
		printf("Erreur de lecture\n");
		return 1;
	}

	if (nombreCases == 0)
	{
		printf("Le tableau doit avoir au moins une case\n");
		return 1;
	}

	tableau = malloc(nombreCases * sizeof(float));
	if (tableau == NULL)
	{
		printf("Erreur d'allocation mémoire\n");
		return 1;
	}

	for (i = 0; i < nombreCases; ++i)
	{
		printf("Entrez le nombre %zd: ", i + 1);
		err = scanf("%f", &tableau[i]);
		if (err != 1)
		{
			printf("Erreur de lecture\n");
			free(tableau);
			return 1;
		}
	}

	for (i = 0; i < nombreCases; ++i)
	{
		printf("Tableau[%zd] = %.2f\n", i, (double)tableau[i]);
	}

	free(tableau);

	return 0;
}
