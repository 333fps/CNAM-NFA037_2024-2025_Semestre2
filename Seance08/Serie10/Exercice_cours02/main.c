#include <stdio.h>
#include <stdlib.h>

#define FILENAME "Exercice_cours02.dat"
#define NUM_DOUBLE 20

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
	double reel = 0.02;
	int i;
	double T1[NUM_DOUBLE];
	FILE* file = NULL;

	for ( i = 0; i < NUM_DOUBLE; ++i )
	{
		T1[i] = i * reel;
	}

	printf( "Tableau de réels avant écriture dans %s:\n", FILENAME );
	for ( i = 0; i < NUM_DOUBLE; ++i )
	{
		printf( "%f\n", T1[i] );
	}

	file = fopen( FILENAME, "wb" );
	if ( !file )
	{
		printf( "Impossible de créer le fichier %s\n", FILENAME );

		return FAILURE;
	}

	fwrite( T1, sizeof( double ), NUM_DOUBLE, file );
	fclose( file );

	return SUCCESS;
}

enum Result LitBin( void )
{
	double T2[NUM_DOUBLE];
	FILE* file = NULL;
	int i;

	file = fopen( FILENAME, "rb" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );

		return FAILURE;
	}

	fread( T2, sizeof( double ), NUM_DOUBLE, file );
	fclose( file );

	printf( "Tableau de réels après lecture dans %s:\n", FILENAME );
	for ( i = 0; i < NUM_DOUBLE; ++i )
	{
		printf( "%f\n", T2[i] );
	}

	return SUCCESS;
}
