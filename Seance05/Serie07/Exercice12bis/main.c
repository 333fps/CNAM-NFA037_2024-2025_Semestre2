#include <stdio.h>
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
		return 1;
	}

	if ( strlen( heure ) != 5 || heure[2] != 'H' )
	{
		printf( "Format d'heure invalide (attendu: xxHxx)\n" );
		return 1;
	}

	if ( Miroir( heure, 0, (int)strlen( heure ) - 1 ) )
	{
		printf( "L'heure %s est une heure miroir\n", heure );
	}
	else
	{
		printf( "L'heure %s n'est pas une heure miroir\n", heure );
	}

	return 0;
}

int Miroir( char* heure, int debut, int fin )
{
	if ( debut >= fin )
	{
		return 1;
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
		return 0;
	}

	return Miroir( heure, debut + 1, fin - 1 );
}
