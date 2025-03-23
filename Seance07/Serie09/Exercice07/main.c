#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void Modif( char* mot );
void Affiche( char* mot );

int main( void )
{
	char mot[MAX_LENGTH];

	printf( "Veuillez saisir un mot: " );
	(void)scanf( "%99s", mot );

	printf( "\nMot saisi: %s\n", mot );

	Modif( mot );
	Affiche( mot );
	Modif( mot );
	Affiche( mot );

	return EXIT_SUCCESS;
}

void Modif( char* mot )
{
	printf( "Quel est votre nouveau mot ?\n" );
	(void)scanf( "%s", mot );
	return;
}

void Affiche( char* mot )
{
	printf( "Mot après modification: %s\n", mot );
}
