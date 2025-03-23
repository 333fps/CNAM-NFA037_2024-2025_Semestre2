#include <stdio.h>

double hauteur_balle( double hauteur, int rebonds );

int main( void )
{
	double hauteur;
	int rebonds;
	int err;

	printf( "Entrez la hauteur initiale de la balle: " );
	err = scanf( "%lf", &hauteur );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Entrez le nombre de rebonds: " );
	err = scanf( "%d", &rebonds );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Hauteur de la balle après %d rebonds: %.2f\n", rebonds, hauteur_balle( hauteur, rebonds ) );

	return 0;
}

double hauteur_balle( double hauteur, int rebonds )
{
	if ( rebonds == 0 )
	{
		return hauteur;
	}
	else
	{
		return hauteur_balle( hauteur / 2, rebonds - 1 );
	}
}
