#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float note;
	int erreur;

	printf( "Entrez une note : " );

	erreur = scanf( "%f", &note );
	if ( erreur != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	if ( note < 0 || note > 20 )
	{
		printf( "La note doit être comprise entre 0 et 20\n" );
		return EXIT_FAILURE;
	}

	if ( note == 0.f )
	{
		printf( "Nul\n" );
	}
	else if ( note < 5 )
	{
		printf( "Catastrophique\n" );
	}
	else if ( note < 8 )
	{
		printf( "Ajourné\n" );
	}
	else if ( note < 10 )
	{
		printf( "Insuffisant\n" );
	}
	else if ( note < 12 )
	{
		printf( "Passable\n" );
	}
	else if ( note < 14 )
	{
		printf( "Assez bien\n" );
	}
	else if ( note < 16 )
	{
		printf( "Bien\n" );
	}
	else
	{
		printf( "Très bien\n" );
	}

	return EXIT_SUCCESS;
}
