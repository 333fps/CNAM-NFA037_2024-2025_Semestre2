#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BilletDeTrain
{
	int numero;
	float prix;
	int train;
	int voiture;
	int place;
	char gareDepart[100];
	int jourDepart;
	int heureDepart;
	char gareArrivee[100];
	int jourArrivee;
	int heureArrivee;
};

int trouverBilletPlusCher( const struct BilletDeTrain billets[], int nombreBillets );
void afficherBilletPlusCher( const struct BilletDeTrain billets[], int nombreBillets );

int main( void )
{
	struct BilletDeTrain billets[3];
	int err;
	int i;

	for ( i = 0; i < 3; i++ )
	{
		printf( "\n=== CREATION DU BILLET DE TRAIN #%d ===\n\n", i + 1 );

		printf( "Numero du billet: " );
		err = scanf( "%d", &billets[i].numero );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}

		printf( "Prix du billet: " );
		err = scanf( "%f", &billets[i].prix );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}

		printf( "Numero du train: " );
		err = scanf( "%d", &billets[i].train );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}

		printf( "Numero de voiture: " );
		err = scanf( "%d", &billets[i].voiture );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}

		printf( "Numero de place: " );
		err = scanf( "%d", &billets[i].place );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}

		printf( "Gare de depart: " );
		err = scanf( "%99s", billets[i].gareDepart );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}

		printf( "Gare d'arrivee: " );
		err = scanf( "%99s", billets[i].gareArrivee );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}

		printf( "Jour de depart (1-31): " );
		err = scanf( "%d", &billets[i].jourDepart );
		if ( err != 1 || billets[i].jourDepart < 1 || billets[i].jourDepart > 31 )
		{
			printf( "Jour invalide\n" );
			return EXIT_FAILURE;
		}

		printf( "Heure de depart (0-23): " );
		err = scanf( "%d", &billets[i].heureDepart );
		if ( err != 1 || billets[i].heureDepart < 0 || billets[i].heureDepart > 23 )
		{
			printf( "Heure invalide\n" );
			return EXIT_FAILURE;
		}

		printf( "Jour d'arrivee (1-31): " );
		err = scanf( "%d", &billets[i].jourArrivee );
		if ( err != 1 || billets[i].jourArrivee < 1 || billets[i].jourArrivee > 31 )
		{
			printf( "Jour invalide\n" );
			return EXIT_FAILURE;
		}

		printf( "Heure d'arrivee (0-23): " );
		err = scanf( "%d", &billets[i].heureArrivee );
		if ( err != 1 || billets[i].heureArrivee < 0 || billets[i].heureArrivee > 23 )
		{
			printf( "Heure invalide\n" );
			return EXIT_FAILURE;
		}
	}

	afficherBilletPlusCher( billets, 3 );

	return EXIT_SUCCESS;
}

int trouverBilletPlusCher( const struct BilletDeTrain billets[], int nombreBillets )
{
	int indexPlusCher = 0;
	float prixMax = billets[0].prix;
	int i;

	for ( i = 1; i < nombreBillets; i++ )
	{
		if ( billets[i].prix > prixMax )
		{
			prixMax = billets[i].prix;
			indexPlusCher = i;
		}
	}

	return indexPlusCher;
}

void afficherBilletPlusCher( const struct BilletDeTrain billets[], int nombreBillets )
{
	int indexPlusCher = trouverBilletPlusCher( billets, nombreBillets );

	printf( "\n=== BILLET LE PLUS CHER ===\n" );
	printf( "Prix: %.2f EUR\n", (double)billets[indexPlusCher].prix );
	printf( "Trajet: %s -> %s\n",
		billets[indexPlusCher].gareDepart,
		billets[indexPlusCher].gareArrivee );
}
