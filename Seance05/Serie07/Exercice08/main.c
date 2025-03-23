#include <stdio.h>
#include <stdlib.h>

double capital_a_terme( double capital, double taux, int annees );

int main( void )
{
	double capitalInitial;
	double taux;
	int annees;
	int err;

	printf( "Entrez le capital initial: " );
	err = scanf( "%lf", &capitalInitial );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Entrez le taux d'intérêt: " );
	err = scanf( "%lf", &taux );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Entrez le nombre d'années: " );
	err = scanf( "%d", &annees );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Capital à terme: %.2f\n", capital_a_terme( capitalInitial, taux, annees ) );

	return EXIT_SUCCESS;
}

double capital_a_terme( double capital, double taux, int annees )
{
	if ( annees == 0 )
	{
		return capital;
	}
	else
	{
		return capital_a_terme( ( capital + capital * taux / 100 ), taux, annees - 1 );
	}
}
