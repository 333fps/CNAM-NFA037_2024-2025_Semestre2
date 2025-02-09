#include <stdio.h>

int main(void)
{
	int entier;
	int err;

	printf("Saisir un entier: ");

	err = scanf("%d", &entier);
	if (err != 1)
	{
		printf("Erreur de saisie\n");
		return 1;
	}

	{
		/*
			Selon l'énoncé, on veut donc un tableau de entier * entier éléments
			En x on a les chiffres de 1 à entier
			En y on a les chiffres de 1 à entier
			En gros une matrice de entier * entier...
		*/
		int tailleTableau = entier * entier;

		{
			int k;
			for (k = 0; k < tailleTableau; k++)
			{
				printf("%d%d\n", (k / entier) + 1, (k % entier) + 1);
			}
		}
	}

	return 0;
}
