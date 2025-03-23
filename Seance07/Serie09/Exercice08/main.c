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

int main( void )
{
	struct BilletDeTrain billet;
	int err;

	printf( "=== CREATION D'UN BILLET DE TRAIN ===\n\n" );

	printf( "Numero du billet: " );
	err = scanf( "%d", &billet.numero );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Prix du billet: " );
	err = scanf( "%f", &billet.prix );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Numero du train: " );
	err = scanf( "%d", &billet.train );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Numero de voiture: " );
	err = scanf( "%d", &billet.voiture );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Numero de place: " );
	err = scanf( "%d", &billet.place );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Gare de depart: " );
	err = scanf( "%99s", billet.gareDepart );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Jour de depart (1-31): " );
	err = scanf( "%d", &billet.jourDepart );
	if ( err != 1 || billet.jourDepart < 1 || billet.jourDepart > 31 )
	{
		printf( "Jour invalide\n" );
		return EXIT_FAILURE;
	}

	printf( "Heure de depart (0-23): " );
	err = scanf( "%d", &billet.heureDepart );
	if ( err != 1 || billet.heureDepart < 0 || billet.heureDepart > 23 )
	{
		printf( "Heure invalide\n" );
		return EXIT_FAILURE;
	}

	printf( "Gare d'arrivee: " );
	err = scanf( "%99s", billet.gareArrivee );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Jour d'arrivee (1-31): " );
	err = scanf( "%d", &billet.jourArrivee );
	if ( err != 1 || billet.jourArrivee < 1 || billet.jourArrivee > 31 )
	{
		printf( "Jour invalide\n" );
		return EXIT_FAILURE;
	}

	printf( "Heure d'arrivee (0-23): " );
	err = scanf( "%d", &billet.heureArrivee );
	if ( err != 1 || billet.heureArrivee < 0 || billet.heureArrivee > 23 )
	{
		printf( "Heure invalide\n" );
		return EXIT_FAILURE;
	}

	printf( "\n======================================\n" );
	printf( "        BILLET DE TRAIN N° %d        \n", billet.numero );
	printf( "======================================\n" );
	printf( "Train: %d   Voiture: %d   Place: %d\n",
		billet.train, billet.voiture, billet.place );
	printf( "--------------------------------------\n" );
	printf( "DEPART: %s\n", billet.gareDepart );
	printf( "Jour %d a %d:00\n", billet.jourDepart, billet.heureDepart );
	printf( "--------------------------------------\n" );
	printf( "ARRIVEE: %s\n", billet.gareArrivee );
	printf( "Jour %d a %d:00\n", billet.jourArrivee, billet.heureArrivee );
	printf( "--------------------------------------\n" );
	printf( "PRIX: %.2f EUR\n", (double)billet.prix );
	printf( "======================================\n" );

	return EXIT_SUCCESS;
}
