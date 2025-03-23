#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main( void )
{
	char chaine[MAX_LENGTH];
	char caractere;
	int i, longueur;
	int count = 0;

	printf( "Veuillez saisir une chaîne de caractères: " );
	fgets( chaine, MAX_LENGTH, stdin );

	longueur = (int)strlen( chaine );
	if ( longueur > 0 && chaine[longueur - 1] == '\n' )
	{
		chaine[longueur - 1] = '\0';
		longueur--;
	}

	printf( "Quel caractère souhaitez-vous rechercher? " );
	caractere = (char)getchar();

	while ( getchar() != '\n' )
		;

	printf( "\nRésultats de la recherche pour '%c':\n", caractere );

	for ( i = 0; i < longueur; i++ )
	{
		if ( chaine[i] == caractere )
		{
			printf( "Trouvé à la position %d\n", i + 1 );
			count++;
		}
	}

	if ( count > 0 )
	{
		printf( "\nLe caractère '%c' a été trouvé %d fois dans la chaîne.\n", caractere, count );
	}
	else
	{
		printf( "\nLe caractère '%c' n'a pas été trouvé dans la chaîne.\n", caractere );
	}

	return EXIT_SUCCESS;
}
