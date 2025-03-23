#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int entier1;
	int entier2;
	int err;

	printf( "Entrez un premier entier : " );
	err = scanf( "%d", &entier1 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Entrez un second entier : " );
	err = scanf( "%d", &entier2 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	if ( entier1 > entier2 )
	{
		printf( "Le premier entier est plus grand que le second.\n" );
	}
	else if ( entier1 < entier2 )
	{
		printf( "Le premier entier est plus petit que le second.\n" );
	}
	else
	{
		printf( "Les deux entiers sont égaux\n" );
	}

	return EXIT_SUCCESS;
}
