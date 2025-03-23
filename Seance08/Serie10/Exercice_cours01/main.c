#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice_cours01.dat"

enum Result
{
	SUCCESS = 0,
	FAILURE
};

enum Result EcritBin( void );
enum Result LitBin( void );

int main( void )
{
	enum Result result;

	result = EcritBin();
	if ( result == FAILURE )
	{
		printf( "La fonction EcritBin a échoué\n" );

		return EXIT_FAILURE;
	}

	result = LitBin();
	if ( result == FAILURE )
	{
		printf( "La fonction LitBin a échoué\n" );

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

enum Result EcritBin( void )
{
	FILE* file = NULL;
	int a = 10;
	double b = 3.14;

	file = fopen( FILENAME, "wb" );
	if ( !file )
	{
		printf( "Impossible de créer le fichier %s\n", FILENAME );

		return FAILURE;
	}

	fwrite( &a, sizeof( int ), 1, file );
	fwrite( &b, sizeof( double ), 1, file );

	fclose( file );

	return SUCCESS;
}

enum Result LitBin( void )
{
	FILE* file = NULL;
	int a;
	double b;

	file = fopen( FILENAME, "rb" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );

		return FAILURE;
	}

	fread( &a, sizeof( int ), 1, file );
	fread( &b, sizeof( double ), 1, file );

	fclose( file );

	printf( "L'entier est %d et le réel est %f.\n", a, b );

	return SUCCESS;
}
