#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main( void )
{
	char mot[MAX_LENGTH];
	int i, longueur;

	printf( "Veuillez saisir un mot: " );
	(void)scanf( "%99s", mot );

	longueur = (int)strlen( mot );

	printf( "\nMot saisi: %s\n", mot );
	printf( "Longueur du mot: %d\n", longueur );

	printf( "\nAffichage caractère par caractère:\n" );
	for ( i = 0; i < longueur; i++ )
	{
		printf( "Caractère #%d: %c\n", i + 1, mot[i] );
	}

	printf( "\nMot en majuscules: " );
	for ( i = 0; i < longueur; i++ )
	{
		printf( "%c", toupper( mot[i] ) );
	}
	printf( "\n" );

	printf( "\nMot en minuscules: " );
	for ( i = 0; i < longueur; i++ )
	{
		printf( "%c", tolower( mot[i] ) );
	}
	printf( "\n" );

	printf( "\nMot à l'envers: " );
	for ( i = longueur - 1; i >= 0; i-- )
	{
		printf( "%c", mot[i] );
	}
	printf( "\n" );

	return 0;
}
