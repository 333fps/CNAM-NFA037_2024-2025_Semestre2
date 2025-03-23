#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Miroir( char* heure, int indice, int longueur );

int main( void )
{
	char heure[6];
	int err;

	printf( "Entrez une heure au format xxHxx: " );
	err = scanf( "%5s", heure );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	if ( strlen( heure ) != 5 || heure[2] != 'H' )
	{
		printf( "Format d'heure invalide (attendu: xxHxx)\n" );
		return EXIT_FAILURE;
	}

	if ( Miroir( heure, 0, (int)strlen( heure ) - 1 ) )
	{
		printf( "L'heure %s est une heure miroir\n", heure );
	}
	else
	{
		printf( "L'heure %s n'est pas une heure miroir\n", heure );
	}

	return EXIT_SUCCESS;
}

int Miroir( char* heure, int debut, int fin )
{
	if ( debut >= fin )
	{
		return EXIT_FAILURE;
	}

	if ( heure[debut] == 'H' )
	{
		return Miroir( heure, debut + 1, fin );
	}
	if ( heure[fin] == 'H' )
	{
		return Miroir( heure, debut, fin - 1 );
	}

	if ( heure[debut] != heure[fin] )
	{
		return EXIT_SUCCESS;
	}

	return Miroir( heure, debut + 1, fin - 1 );
}
