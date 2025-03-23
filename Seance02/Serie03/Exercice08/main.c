#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float nombre1;
	float nombre2;
	int err;

	printf( "Entrez un nombre : " );
	err = scanf( "%f", &nombre1 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Entrez un autre nombre : " );
	err = scanf( "%f", &nombre2 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	if ( ( nombre1 > 0 && nombre2 < 0 ) || ( nombre1 < 0 && nombre2 > 0 ) )
	{
		printf( "Bravo!" );
	}
	else
	{
		printf( "Perdu!" );
	}

	return EXIT_SUCCESS;
}
