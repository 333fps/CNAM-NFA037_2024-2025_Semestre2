#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	char ansiCode;

	int err;

	printf( "Saisir un code ANSI... \n" );
	err = scanf( "%s", &ansiCode );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	printf( "Le caractère correspondant au code ASCII %d est %c\n", ansiCode, ansiCode );

	return EXIT_SUCCESS;
}
