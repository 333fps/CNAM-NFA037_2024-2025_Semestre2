#include <stdio.h>
#include <math.h>

int main( void )
{
	int annee;
	int err;

	printf( "Entrez une année : " );

	err = scanf( "%d", &annee );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	if ( annee < 0 )
	{
		printf( "L'année doit être positive\n" );
		return 1;
	}

	if ( ( annee % 4 == 0 && annee % 100 != 0 ) || annee % 400 == 0 )
	{
		printf( "L'année %d est bissextile\n", annee );
	}
	else
	{
		printf( "L'année %d n'est pas bissextile\n", annee );
	}

	return 0;
}
