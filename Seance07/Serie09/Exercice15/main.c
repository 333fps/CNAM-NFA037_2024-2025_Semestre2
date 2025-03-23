#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crypte( char* mot );

int main( void )
{
	char mot[100];

	printf( "Veuillez saisir un mot: " );
	(void)scanf( "%99s", mot );

	printf( "\nMot saisi: %s\n", mot );

	crypte( mot );

	printf( "Mot crypté: %s\n", mot );

	return EXIT_SUCCESS;
}

void crypte( char* mot )
{
	int i;
	int longueur = (int)strlen( mot );

	for ( i = 0; i < longueur; i++ )
	{
		if ( mot[i] >= 'a' && mot[i] <= 'z' )
		{
			mot[i] = ( mot[i] - 'a' + 1 ) % 26 + 'a';
		}
		else if ( mot[i] >= 'A' && mot[i] <= 'Z' )
		{
			mot[i] = ( mot[i] - 'A' + 1 ) % 26 + 'A';
		}
	}
}
