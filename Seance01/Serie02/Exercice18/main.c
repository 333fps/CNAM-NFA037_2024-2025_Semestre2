#include <stdio.h>
#include <math.h>

int main(void)
{
	int entier;
	double carre;
	int resultat;
	int err;

	printf("Saisir un entier : \n");

	err = scanf("%d", &entier);
	if (err != 1)
	{
		printf("Erreur de saisie\n");
		return 1;
	}

	carre = pow(entier, 2);
	resultat = (int)carre;

	printf("Le nombre %d élevé à la puissance de 2 vaut: %d.\n", entier, resultat);

	return 0;
}
