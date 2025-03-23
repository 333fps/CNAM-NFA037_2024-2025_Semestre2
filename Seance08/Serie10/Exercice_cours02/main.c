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
	size_t itemsWritten;

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

	itemsWritten = fwrite( T1, sizeof( double ), NUM_DOUBLE, file );
	itemsWritten = fwrite( T1, sizeof( double ), NUM_DOUBLE, file );
	if ( itemsWritten != NUM_DOUBLE )
	{
		printf( "Erreur lors de l'écriture du tableau: %u éléments écrits sur %d attendus\n",
			(unsigned)itemsWritten, NUM_DOUBLE );
		fclose( file );
		return FAILURE;
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier\n" );
		return FAILURE;
	}

	return SUCCESS;
}

enum Result LitBin( void )
{
	double T2[NUM_DOUBLE];
	FILE* file = NULL;
	int i;
	size_t itemsRead;

	file = fopen( FILENAME, "rb" );
	if ( !file )
	{
		printf( "Impossible d'ouvrir le fichier %s\n", FILENAME );
		return FAILURE;
	}

	itemsRead = fread( T2, sizeof( double ), NUM_DOUBLE, file );
	if ( itemsRead != NUM_DOUBLE )
	{
		printf( "Erreur lors de la lecture du tableau: %u éléments lus sur %d attendus\n",
			(unsigned)itemsRead, NUM_DOUBLE );
		fclose( file );
		return FAILURE;
	}

	if ( fclose( file ) == EOF )
	{
		printf( "Erreur lors de la fermeture du fichier\n" );
		return FAILURE;
	}

	printf( "Tableau de réels après lecture dans %s:\n", FILENAME );
	for ( i = 0; i < NUM_DOUBLE; ++i )
	{
		printf( "%f\n", T2[i] );
	}

	return SUCCESS;
}
