#include <stdio.h>

int main(void)
{
	float Tableau[5];
	int err;
	size_t i;
	struct
	{
		size_t position;
		float plusPetit;
	} data;

	for (i = 0; i < sizeof(Tableau) / sizeof(float); ++i)
	{
		printf("Entrez le nombre %zd: ", (i + 1));
		err = scanf("%f", &Tableau[i]);
		if (err != 1)
		{
			printf("Erreur de lecture\n");
			return 1;
		}
	}

	data.position = 0;
	data.plusPetit = Tableau[0];
	for (i = 0; i < sizeof(Tableau) / sizeof(float); ++i)
	{
		if (Tableau[i] < data.plusPetit)
		{
			data.position = i;
			data.plusPetit = Tableau[i];
		}
	}

	for (i = 0; i < sizeof(Tableau) / sizeof(float); ++i)
	{
		printf("Tableau[%zd] = %f\n", i, (double)Tableau[i]);
	}

	printf("Le plus petit nombre est %f et est situé à la position: %zd\n", (double)data.plusPetit, data.position);

	return 0;
}
