#include <stdio.h>
#include <stdlib.h>

#define MAX_NOM 10

int main( void )
{
	char nom[MAX_NOM];
	int err;

	printf( "Entrez votre prénom (max %d caractères) : ", MAX_NOM - 1 );

	err = scanf( "%9s", nom );
	if ( err != 1 )
	{
		printf( "Erreur de lecture\n" );
		return EXIT_FAILURE;
	}

	printf( "Bonjour %s !\n", nom );
	return EXIT_SUCCESS;
}
